# This is intended to be run in the /test-results/gcc-13 subdirectory
# in a Linux shell with gcc 13 installed
#
cp ../*.cpp .
rm -f *.output
count=0
exe_count=0
g++ --version > gcc-version.output 2>&1
for f in *.cpp
do
    let count=count+1
    printf "[%s] Starting gcc 13 %s\n" "$count" "$f"
    g++ -I../../../include -std=c++2b -pthread -Wold-style-cast -Wunused-parameter -o test.exe $f > $f.output 2>&1
    rm -f $f
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
