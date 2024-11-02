@echo off
cppfront -_gen_build > source\build.info
@echo Build stamp updated to:
type source\build.info
