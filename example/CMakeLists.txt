cmake_minimum_required(VERSION 3.23)
project(cpp2-example)

find_package(cppfront REQUIRED)
# This works, too:
# add_subdirectory(../ cppfront)

add_executable(main main.cpp2)
