#!/bin/bash

################
usage() {
    echo "Usage: $0 -c <compiler> [-t <tests to run>]"
    echo "    -c <compiler>     The compiler to use for the test"
    echo "    -t <tests to run> Runs only the provided, comma-separated tests (filenames including .cpp2)"
    echo "                      If the argument is not used all tests are run"
    exit 1
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

    if [[ $untracked -eq 1 ]]; then
        echo "            The $description is not tracked by git:"
        echo "                $file"
        # Add the file to the index to be able to diff it...
        git add "$file"
        # ... print the diff ...
        git --no-pager diff HEAD -- "$file"
        # ... and remove the file from the diff
        git rm --cached -- "$file" > /dev/null 2>&1
        
        failure=1
    else
        # Compare the content with the refernece value checked in git
        diff_output=$(git diff --ignore-cr-at-eol -- "$file")
        if [[ -n "$diff_output" ]]; then
            echo "            Non-matching $description:"
            printf "\n$diff_output\n\n"
            failure=1
        fi
    fi
}

optstring="c:t:"
while getopts ${optstring} arg; do
  case "${arg}" in
    c)
        cxx_compiler="${OPTARG}"
        ;;
    t)
        # Replace commas with spaces
        chosen_tests=${OPTARG/,/ }
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

tests=$(ls | grep ".cpp2$")
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

expected_results_dir="test-results"

################
# Get the directory with the exec outputs and compilation command
if [[ "$cxx_compiler" == *"cl.exe"* ]]; then
    compiler_cmd='cl.exe -nologo -std:c++latest -MD -EHsc -I ..\include -I ..\..\..\include -experimental:module -Fe:'
    exec_out_dir="$expected_results_dir/msvc-2022"
    compiler_version=$(cl.exe)
else
    compiler_cmd="$cxx_compiler -I../include -I../../../include -std=c++20 -pthread -o "
    
    compiler_ver=$("$cxx_compiler" --version)
    if [[ "$compiler_ver" == *"Apple clang version 14.0"* ]]; then
        exec_out_dir="$expected_results_dir/apple-clang-14"
    elif [[ "$compiler_ver" == *"clang version 12.0"* ]]; then 
        exec_out_dir="$expected_results_dir/clang-12"
    elif [[ "$compiler_ver" == *"clang version 15.0"* ]]; then 
        exec_out_dir="$expected_results_dir/clang-15"
    elif [[ "$compiler_ver" == *"g++-10"* ]]; then
        exec_out_dir="$expected_results_dir/gcc-10"
    elif [[ "$compiler_ver" == *"g++-12"* ||
            "$compiler_ver" == *"g++-13"*
         ]]; then
        exec_out_dir="$expected_results_dir/gcc-13"
    fi

    compiler_version=$("$cxx_compiler" --version)
fi

if [[ -d "$exec_out_dir" ]]; then
    printf "Full compiler version for '$cxx_compiler':\n$compiler_version\n\n"

    printf "Directory with reference compilation/execution files to use:\n$exec_out_dir\n\n"
else
    printf "not found for compiler: '$cxx_compiler'\n\n"
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
failed_tests=()
failed_compilations=()
skipped_tests=()
echo "Running regression tests"
for test_file in $tests; do
    test_name=${test_file%.*}
    expeced_output="$expected_results_dir/$test_file.output"
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
    ./"$cppfront_cmd" "$test_file" -o "$expected_src" $opt > "$expeced_output" 2>&1

    failure=0
    compiler_issue=0
    ########
    # The C++1 generation output has to exist and to be tracked by git
    check_file "$expeced_output" "Cpp1 generation output file"

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
         $compiler_cmd"$test_bin" \
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
    elif [[ $(cat "$expeced_output") != *"error"* ]]; then
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
# Report missing reference data direcotry
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
