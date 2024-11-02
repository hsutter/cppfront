@echo off
cd source
cppfront reflect.h2 -verb
cd ..\include
cppfront cpp2regex.h2 -verb
cd..
