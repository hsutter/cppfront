REM This is intended to be run in the /test-results/msvc-2022-c++20 directory
REM in a VS2022 Command Prompt (which sets the path and other environment)
REM
REM After installing VS2022, to finish setting up std modules in your environment, run:
REM     cl /std:c++20 /EHsc /nologo /W4 /MD /c "%VCToolsInstallDir%\modules\std.ixx"
REM     cl /std:c++20 /EHsc /nologo /W4 /MD /c "%VCToolsInstallDir%\modules\std.compat.ixx"
REM More info: https://learn.microsoft.com/en-us/cpp/cpp/tutorial-import-stl-named-module?view=msvc-170
REM
@echo off
SETLOCAL EnableDelayedExpansion
copy ..\*.cpp .
del *.output
set count=0
set exe_count=0
cl 1>NUL 2> MSVC-version.output
for %%f in (*.cpp) do (
    set /a count+=1
    echo [!count!] Starting MSVC cl.exe %%f
    cl.exe %%f -Fe"test" -nologo -std:c++20 -MD -EHsc -I ..\..\..\include std.obj std.compat.obj >> %%f.output 2>&1
    del %%f
    IF EXIST "test.exe" (
        set /a exe_count+=1
        echo.    Starting executable
        test.exe > %%f.execution 2>&1
        del test.exe
    )
)
del pure2-*.obj mixed-*.obj *.exp *.lib
echo.
echo Done: %count% .cpp tests compiled
echo.
echo.      %exe_count% executables generated and run
