REM This is intended to be run in the /test-results directory
REM A copy is in the parent directory just for convenience in case of accidental deletion.
REM
@echo off
copy ..\*.cpp2 .
set count=0
for %%f in (mixed-*.cpp2) do (
    echo Starting cppfront.exe %%f
    C:\GitHub\cppfront\x64\Debug\cppfront.exe %%f > %%f.output 2>&1
    del %%f
    set /a count+=1
)
for %%f in (pure2-*.cpp2) do (
    echo Starting cppfront.exe %%f -p
    C:\GitHub\cppfront\x64\Debug\cppfront.exe %%f -p > %%f.output 2>&1
    del %%f
    set /a count+=1
)
echo Done: %count% tests