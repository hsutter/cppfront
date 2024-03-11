# This is intended to be run in the /test-results/apple-clang-14 subdirectory
# in a macOS shell with clang++ installed
#
cp ../*.cpp .
rm -f *.output *.execution
count=0
exe_count=0
clang++ --version > clang-version.output 2>&1
for f in *.cpp
do
    printf "Starting apple clang++ %s\n" "$f"
    clang++ -I../../../include -std=c++2b -pthread -o test.exe $f > $f.output 2>&1
    rm -f $f
    let count=count+1
    if test -f "test.exe"; then
        let exe_count=exe_count+1
        printf "    Starting executable\n"
        ./test.exe > $f.execution 2>&1
        rm -f test.exe
    fi
done
rm -f *.obj *.exp *.lib
printf "\nDone: %s .cpp tests compiled\n" "$count"
printf "\n      %s .cpp executables generated and run\n" "$exe_count"
