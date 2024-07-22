@echo off
setlocal enabledelayedexpansion

:: Loop through all files in the current directory and subdirectories
for /r %%f in (*) do (
    :: Check if the file size is 0 bytes
    if %%~zf==0 (
        :: Remove the empty file
        del "%%f"
    )
)

endlocal
