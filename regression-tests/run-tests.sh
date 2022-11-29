#!/bin/bash

################
if [[ $# -ne 1 ]]; then
    echo "Usage:  bash $0 <c++ compile to use>"
    exit 1;
fi
cxx_compiler=$1

################
echo "Building cppfront using '$cxx_compiler'"
if [ -f cppfront ]; then
    rm cppfront
fi
"$cxx_compiler" ../source/cppfront.cpp --std=c++20 -o cppfront
if [[ $? -ne 0 ]]; then
    echo "Compilation using '$cxx_compiler' failed"
    exit 2
fi

################
failed_tests=()
echo "Running regression tests"
for test_file in $(ls | grep ".cpp2"); do
    test_name=${test_file%.*}
    expected_results_dir="test-results"
    actual_output="$test_name.output"
    expeced_output="$expected_results_dir/$test_file.output"
    actual_src="$test_name.cpp"
    expeced_src="$expected_results_dir/$test_name.cpp"

    # Choose mode - default to mixed code
    descr="mixed cpp1 and cpp2 code"
    opt=""
    # Using naming convention to discriminate pure cpp2 code
    if [[ $test_name == "pure2"* ]]; then
        descr="pure cpp2 code"
        opt="-p"
    fi
    echo "    Testing $descr: $test_name"

    ########
    # Run the translation test
    ./cppfront "$test_file" $opt > "$actual_output" 2>&1

    failure=0
    ########
    # Check the output
    if [ -f "$expeced_output" ]; then
        diff "$actual_output" "$expeced_output" > diff_output 2>&1
        if [[ $? -ne 0 ]]; then
            echo "        Non-matching std out/err:"
            echo
            cat diff_output
            echo
            failure=1
        fi
        rm diff_output
    else
        echo "        Missing expected output file treaded as failure"
        failure=1
    fi
    rm "$actual_output"

    ########
    # Check the generated code
    if [ -f "$actual_src" ]; then
         diff "$actual_src" "$expeced_src" > diff_output 2>&1
        if [[ $? -ne 0 ]]; then
            echo "        Non-matching generated src:"
            echo
            cat diff_output
            echo
            failure=1
        fi
        rm diff_output
        rm "$actual_src"
    elif [[ $(cat "$expeced_output") != *"error"* ]]; then
         echo "        Missing generated src file treaded as failure"
         echo "            Failing compilation message needs to contain 'error'"
         failure=1
    fi

    if [[ $failure -ne 0 ]]; then
        failed_tests+=($test_name)
    fi
done

rm cppfront

################
# Report failed tests
num_failed_tests=$(wc -w <<< ${failed_tests[@]})
echo
if [ $num_failed_tests -ne 0 ]; then
    echo "Failed tests: $num_failed_tests"
    for failed_test in ${failed_tests[@]}; do
        echo "    $failed_test"
    done
else
    echo "All tests passed"
fi
exit $num_failed_tests
