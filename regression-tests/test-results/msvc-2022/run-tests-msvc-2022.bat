REM This is intended to be run in the /test-results/msvc-2022 directory
REM in a VS2022 Command Prompt (which sets the path and other environment)
REM
@echo off
copy ..\*.cpp .
del *.output
set count=0
set exe_count=0
cl 1>NUL 2> MSVC-version.output
for %%f in (*.cpp) do (
    echo Starting MSVC cl.exe %%f
    cl.exe %%f -Fe"test" -nologo -std:c++latest -MD -EHsc -I c:\github\cppfront\include -experimental:module >> %%f.output 2>&1
    del %%f
    set /a count+=1
    IF EXIST "test.exe" (
        set /a exe_count+=1
        echo.    Starting executable
        test.exe > %%f.execution 2>&1
        del test.exe
    )
)
del *.obj *.exp *.lib
echo.
echo Done: %count% .cpp tests compiled
echo.
echo.      %exe_count% executables generated and run