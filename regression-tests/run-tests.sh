#!/bin/bash
rm -rf ./test-results/*
cp ./*.cpp2 ./test-results

stats() {
    echo "$1 SUCCESS"
    echo "$2 FAILED"
}

declare -a transpile_success
declare -a transpile_failure
transpile() {
    for filename in `find ./test-results -name "$1"`; do
        cppfront $2 $filename &> ./$filename-output 2>&1 && transpile_success+=($filename) || transpile_failure+=($filename)
    done
}

declare -a compile_success
declare -a compile_failure
compile() {
    for filename in `find ./test-results -regex '.*\(cpp\)$' -type f`; do
        g++-$1 -I$2 -o $filename.out $filename -std=c++20 >> ./$filename-output 2>&1 \
        && compile_success+=($filename) \
        || compile_failure+=($filename)
    done
}

declare -a run_success
declare -a run_failure
run() {
    for filename in `find ./test-results -regex '.*\(out\)$' -type f`; do
        ./$filename >> ./$filename-output 2>&1 \
        && run_success+=($filename) \
        || run_failure+=($filename)
    done
}

#### TRANSPILE ####
echo "TRANSPILE:"
transpile "mixed*.cpp2"
transpile "pure*.cpp2" "-p"

stats ${#transpile_success[@]} ${#transpile_failure[@]}
printf '%s\n' "${transpile_failure[@]}"

#### COMPILE ####
echo "COMPILE:"
compile 11 ../include
stats ${#compile_success[@]} ${#compile_failure[@]}
printf '%s\n' "${compile_failure[@]}"

#### EXECUTE ####
echo "RUN"
run
stats ${#run_success[@]} ${#run_failure[@]}
printf '%s\n' "${run_failure[@]}"
