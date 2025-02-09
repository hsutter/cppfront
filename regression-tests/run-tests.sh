#!/bin/bash

################
usage() {
    echo "Usage: $0 -c <compiler> [-l <run label>] [-t <tests to run>]"
    echo "    -c <compiler>     The compiler to use for the test"
    echo "    -s <cxx_std>      The C++ standard to compile with (e.g. 'c++20', 'c++2b', 'c++latest' depending on the compiler)"
    echo "    -d <stdlib>       Clang-only: the C++ Standard Library to link with ('libstdc++', 'libc++', or 'default' for platform default)"
    echo "    -l <run label>    The label to use in output patch file name"
    echo "    -t <tests to run> Runs only the provided, comma-separated tests (filenames including .cpp2)"
    echo "                      If the argument is not used all tests are run"
    exit 1
}

################
# Check diff of the provided file using the given diff options
# If the diff is not empty print it with the provided message
report_diff () {
    file="$1"
    error_msg="$2"
    patch_file="$3"
    # The remaining arguments will be passed to git
    shift 3
    diff_opts="$@"

    # Compare the content with the reference value checked in git
    diff_output=$(git diff $diff_opts -- "$file")
    if [[ -n "$diff_output" ]]; then
        echo "            $error_msg:"
        echo "                $file"
        # $diff_output cannot be put directly in the format string
        # Otherwise \ might be interpreted as an escape character
        printf "\n%s\n\n" "$diff_output" | tee -a "$patch_file"
        failure=1
    fi
}

################
# Check file existence and compare its state against the version in git
check_file () {
    file="$1"
    description="$2"

    if [[ ! -f "$file" ]]; then
        echo "            The $description does not exist:"
        echo "                $file"
        failure=1
        return
    fi

    # Check if the file is tracked by git
    git ls-files --error-unmatch "$file" > /dev/null 2>&1
    untracked=$?

    patch_file="${label}-${cxx_compiler}-${cxx_std}-${cxx_stdlib}.patch"

    if [[ $untracked -eq 1 ]]; then
        # Untraced files are expected to be empty - report if they are not
        if [[ -s ""$file"" ]]; then
            # Add the file to the index to be able to diff it...
            git add "$file"
            # ... report the diff ...
            report_diff "$file" \
                "The $description is not tracked by git, it is expected to be empty" \
                "$patch_file" \
                "HEAD"
            # ... and remove the file from the index
            git rm --cached -- "$file" > /dev/null 2>&1
        else
            # The file is empty as expected - it can be removed
            rm "$file"
        fi
    else
        # Compare the content with the reference value checked in git
        # Lines includng Windows paths are excluded from diff
        # This is necessary due to characters in those paths on GitHub runners
        # that cause git diff to spuriously flag them
        report_diff "$file" \
            "Non-matching $description" \
            "$patch_file" \
            --ignore-cr-at-eol

        # If the file is tracked an empty report an error
        if [[ $failure != 1 && ! -s "$file" ]]; then
            echo "            Empty tracked file:"
            echo "                $file"
            failure=1
        fi
    fi
}

optstring="c:s:d:l:t:"
while getopts ${optstring} arg; do
  case "${arg}" in
    c)
        cxx_compiler="${OPTARG}"
        ;;
    s)
        cxx_std="${OPTARG}"
        ;;
    d)
        cxx_stdlib="${OPTARG}"
        ;;
    l)
        label="${OPTARG}"
        ;;
    t)
        # Replace commas with spaces
        chosen_tests=${OPTARG//,/ }
        ;;
    \?)
        echo "Invalid option: -${OPTARG}."
        echo
        usage
        ;;
    :)
        echo "Missing option argument for -$OPTARG"
        echo
        usage
        ;;
    *)
      usage
      exit 1
      ;;
  esac
done

if [ -z "$cxx_compiler" ]; then
    echo "Compiler not specified"
    usage
fi

if [ -z "$label" ]; then
    echo "Run label not specified"
    usage
fi

################
# Get the directory with the exec outputs and compilation command
# We also allow each compiler configuration to specify any test files(s) to exclude from running.
expected_results_dir="test-results"
exclude_test_filter=""
if [[ "$cxx_compiler" == *"cl.exe"* ]]; then
    compiler_cmd="cl.exe -nologo -std:${cxx_std} -MD -EHsc -I ..\..\..\include -Fe:"
    exec_out_dir="$expected_results_dir/msvc-2022-${cxx_std}"
    compiler_version=$(cl.exe)
else
    # Verify the compiler command
    which "$cxx_compiler" > /dev/null
    if [[ $? != 0 ]]; then
        printf "The compiler '$cxx_compiler' is not installed\n\n"
        exit 2
    fi

    compiler_version=$("$cxx_compiler" --version)

    if [[ "$compiler_version" == *"Apple clang version 14.0"* ||
          "$compiler_version" == *"Homebrew clang version 15.0"* ]]; then
        exec_out_dir="$expected_results_dir/apple-clang-14"
        # We share the expected results dir for these two compilers, but there is one
        # test which (as expected) fails to compile on both compilers, but has a slightly
        # different error diagnostic because the clang path differs. So we exclude it from
        # running. The alternative would be to duplicate the expected results files, which
        # seems wasteful for just one test (that doesn't even compile).
        exclude_test_filter="pure2-expected-is-as.cpp2"
    elif [[ "$compiler_version" == *"Apple clang version 15.0"* ]]; then
        exec_out_dir="$expected_results_dir/apple-clang-15"
    elif [[ "$compiler_version" == *"clang version 12.0"* ]]; then 
        exec_out_dir="$expected_results_dir/clang-12"
    elif [[ "$compiler_version" == *"clang version 15.0"* ]]; then 
        exec_out_dir="$expected_results_dir/clang-15"
    elif [[ "$compiler_version" == *"clang version 18.1"* ]]; then 
        exec_out_dir="$expected_results_dir/clang-18"
    elif [[ "$compiler_version" == *"g++-10"* ]]; then
        exec_out_dir="$expected_results_dir/gcc-10"
    elif [[ "$compiler_version" == *"g++-12"* ||
            "$compiler_version" == *"g++-13"*
         ]]; then
        exec_out_dir="$expected_results_dir/gcc-13"
    elif [[ "$compiler_version" == *"g++-14"* ]]; then
        exec_out_dir="$expected_results_dir/gcc-14"
    else
        printf "Unhandled compiler version:\n$compiler_version\n\n"
        exit 2
    fi

    # Append the C++ standard (e.g. 'c++20') to the expected output dir name
    exec_out_dir="${exec_out_dir}-${cxx_std}"

    # Clang can link with either libstdc++ or libc++
    # By default clang on ubuntu links with libstdc++ and on macOS links with libc++.
    if [[ "$compiler_version" == *"clang"* ]]; then 
        if [[ "$cxx_stdlib" == "default" || "$cxx_stdlib" == "" ]]; then
            cxx_stdlib_link_arg=""  # Use compiler/platform default
        elif [[ "$cxx_stdlib" == "libstdc++" ]]; then
            cxx_stdlib_link_arg="-stdlib=libstdc++"
        elif [[ "$cxx_stdlib" == *"libc++"* ]]; then

            # Need to install the correct libc++ packages, e.g. `libc++-15-dev` and `libc++abi-15-dev` for clang 15.
            # Our `cxx_stdlib` variable contains the `libc++-XX-dev` package name so we need to create the abi version.
            cxx_stdlib_abi_package="${cxx_stdlib/libc++/libc++abi}"
            printf "Installing packages: $cxx_stdlib $cxx_stdlib_abi_package\n\n"
            sudo apt-get install -y $cxx_stdlib $cxx_stdlib_abi_package

            cxx_stdlib_link_arg="-stdlib=libc++"
            exec_out_dir="${exec_out_dir}-libcpp"
        else
            printf "Unhandled C++ Standard Library option:\n$cxx_stdlib\n\n"
            exit 2
        fi
    else
        cxx_stdlib_link_arg=""  # Use compiler/platform default
    fi

    compiler_cmd="$cxx_compiler -I../../../include -std=$cxx_std $cxx_stdlib_link_arg -pthread -o "
    printf "\ncompiler_cmd: $compiler_cmd\n\n"
fi

if [[ -d "$exec_out_dir" ]]; then
    printf "Full compiler version for '$cxx_compiler':\n$compiler_version\n\n"

    printf "Directory with reference compilation/execution files to use:\n$exec_out_dir\n\n"
else
    printf "Directory with reference compilation/execution files not found for compiler: '$cxx_compiler' at $exec_out_dir\n\n"
    exit 2
fi

################
# Get the list of .cpp2 test files
if [[ -n "$exclude_test_filter" ]]; then
    tests=$(ls | grep ".cpp2$" | grep -v $exclude_test_filter)
else
    tests=$(ls | grep ".cpp2$")
fi
if [[ -n "$chosen_tests" ]]; then
    for test in $chosen_tests; do
        if ! [[ -f "$test" ]]; then
            echo "Requested test ($test) not found"
            exit 1
        fi
    done
    echo "Performing tests:"
    for test in $chosen_tests; do
        echo "    $test"
    done
    echo
    tests="$chosen_tests"
else
    printf "Performing all regression tests\n\n"
fi

################
cppfront_cmd="cppfront.exe"
echo "Building cppfront"
$compiler_cmd"$cppfront_cmd" ../source/cppfront.cpp
if [[ $? -ne 0 ]]; then
    echo "Compilation failed"
    exit 2
fi

################
# Build the `std` and `std.compat` modules so that the regression tests can use them (currently only supported by MSVC)
# in order to support `import std.compat;`.
regression_test_link_obj=""
if [[ "$cxx_compiler" == *"cl.exe"* ]]; then
    echo "Building std and std.compat modules"
    (cd $exec_out_dir; \
     cl.exe -nologo -std:${cxx_std} -MD -EHsc -c "${VCToolsInstallDir}/modules/std.ixx";
     cl.exe -nologo -std:${cxx_std} -MD -EHsc -c "${VCToolsInstallDir}/modules/std.compat.ixx")
    regression_test_link_obj="std.obj std.compat.obj"
fi

################
failed_tests=()
failed_compilations=()
skipped_tests=()
echo "Running regression tests"
for test_file in $tests; do
    test_name=${test_file%.*}
    expected_output="$expected_results_dir/$test_file.output"
    generated_cpp_name=$test_name.cpp
    expected_src="$expected_results_dir/$generated_cpp_name"
    test_bin="test.exe"

    # Choose mode - default to mixed code
    descr="mixed Cpp1 and Cpp2 code"
    opt=""
    # Using naming convention to discriminate pure Cpp2 code
    if [[ $test_name == "pure2"* ]]; then
        descr="pure Cpp2 code"
        opt="-p"
    fi
    echo "    Testing $descr: $test_name.cpp2"

    ########
    # Run the translation test
    echo "        Generating Cpp1 code"
    ./"$cppfront_cmd" "$test_file" -o "$expected_src" $opt > "$expected_output" 2>&1

    failure=0
    compiler_issue=0
    ########
    # The C++1 generation output has to exist and to be tracked by git
    check_file "$expected_output" "Cpp1 generation output file"

    ########
    # Check the generated code
    if [ -f "$expected_src" ]; then
        # The file was generated, so it should be tracked by git
        check_file "$expected_src" "generated Cpp1 file"
        ########
        # Compile and run the generated code in a sub-shell
        expected_src_compil_out="$exec_out_dir/$generated_cpp_name.output"
        expected_src_exec_out="$exec_out_dir/$generated_cpp_name.execution"
        expected_files="$expected_results_dir/$test_name.files"

        echo "        Compiling the generated Cpp1 code"
        
        # For some tests the binary needs to be placed in "$exec_out_dir"
        # For that reason the compilation is done directly in that dir
        # The source is temporarily copied to avoid issues with bash paths in cl.exe
        (cd $exec_out_dir; \
         cp ../../$expected_src $generated_cpp_name;
         $compiler_cmd"$test_bin" $regression_test_link_obj \
                        $generated_cpp_name \
                        > $generated_cpp_name.output 2>&1)
        compilation_result=$?
        rm $exec_out_dir/$generated_cpp_name

        if [ -f "$expected_src_compil_out" ]; then
            # Check for local compiler issues
            if [[ $compilation_result -ne 0 ]]; then
                # Workaround an issue with MSVC missing std modules
                if cat $expected_src_compil_out | grep -q "error C1011"; then
                    echo "            Skipping further checks due to missing std modules support"
                    compiler_issue=1
                fi
            fi
            ########
            # Check the Cpp1 compilation message (if there are no local compiler issues)
            if [[ $compiler_issue -ne 1 ]]; then
                check_file "$expected_src_compil_out" "Cpp1 compilation message file"
            fi
            # Check the result of a successful compilation
            if [[ $compilation_result -eq 0 ]]; then
                ########
                # Execute the compiled code in $exec_out_dir
                echo "        Executing the compiled test binary"
                # Run the binary in a sub-shell in $exec_out_dir so that files are written there
                ( cd "$exec_out_dir"; ./$test_bin > "$generated_cpp_name.execution" 2>&1 )

                check_file "$expected_src_exec_out" "execution output file"
                # If the test generates files check their content
                if [[ -f "$expected_files" ]]; then
                    echo "        Checking files written by the binary"
                    files="$(cat "$expected_files")"
                    for file in ${files/,/ }; do
                        check_file "$exec_out_dir/$file" "file meant to be written by the binary"
                    done
                fi
            fi
        fi
    elif [[ $(cat "$expected_output") != *"error"* ]]; then
         echo "            Missing generated src file treated as failure"
         echo "                Failing compilation message needs to contain 'error'"
         failure=1
    fi

    if [[ $failure -ne 0 ]]; then
        failed_tests+=($test_name)
    fi

    if [[ $compiler_issue -ne 0 ]]; then
        skipped_tests+=($test_name)
    elif [[ $compilation_result -ne 0 ]]; then
        failed_compilations+=($test_name)
    fi
done

################
# Report missing reference data directory
if [[ ! -d "$exec_out_dir" ]]; then
    echo "Reference data directory not found for compiler: '$cxx_compiler'"
    exit 3
fi

################
# Report skipped/failed tests
report_issues() {
    local msg=$1
    shift 1
    local reported_tests=("$@")
    local num_reported_tests=$(wc -w <<< ${reported_tests[@]})
    if [ $num_reported_tests -ne 0 ]; then
        echo "$msg: $num_reported_tests"
        for reported_test in ${reported_tests[@]}; do
            echo "    $reported_test.cpp2"
        done
    fi
    return $num_reported_tests
}

report_issues "Tests skipped due to compiler issues" "${skipped_tests[@]}"
report_issues "Tests with failing compilation step" "${failed_compilations[@]}"
report_issues "Failed tests" "${failed_tests[@]}"
num_failed_tests=$?
if [ $num_failed_tests -eq 0 ]; then
    echo "All tests passed"
fi
exit $num_failed_tests
