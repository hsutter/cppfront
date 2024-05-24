@echo off
cppfront.exe -version > version
del *.cpp *.output
copy ..\*.cpp2 .
set count=0

set STARTTIME=%TIME%

for %%f in (mixed-*.cpp2) do (
    echo Starting cppfront.exe %%f
    cppfront.exe %%f > %%f.output 2>&1
    del %%f
    set /a count+=1
)
for %%f in (pure2-*.cpp2) do (
    echo Starting cppfront.exe %%f -p
    cppfront.exe -p %%f > %%f.output 2>&1
    del %%f
    set /a count+=1
)
set cpp_count=0
for %%A in (*.cpp) do set /a cpp_count+=1
set err_count=0
for %%A in (..\*error.cpp2) do set /a err_count+=1
set /a "total_count=%cpp_count%+%err_count%"
echo.
echo Done: %count% .cpp2 tests compiled
echo.
echo.      %cpp_count% .cpp files generated
echo.      %err_count% error test cases (should not generate .cpp)
echo.      %total_count% total
if %total_count% NEQ %count% (
    echo.      *** MISMATCH: should equal total tests run
)

set ENDTIME=%TIME%
echo.
echo Start time: %STARTTIME%
echo   End time: %ENDTIME%