@echo off
cd source
cppfront reflect.h2 -verb %1
cd ..\include
cppfront cpp2regex.h2 -verb %1
cppfront cpp2taylor.h2 -verb %1
cd..
