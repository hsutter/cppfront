@echo off
copy ..\*.cpp2 .
for %%f in (mixed-*.cpp2) do (
    echo Starting cppfront.exe %%f
    C:\GitHub\cppfront\x64\Debug\cppfront.exe %%f > %%f-output 2>&1
)
for %%f in (pure2-*.cpp2) do (
    echo Starting cppfront.exe %%f -p
    C:\GitHub\cppfront\x64\Debug\cppfront.exe %%f -p > %%f-output 2>&1
)
echo Done