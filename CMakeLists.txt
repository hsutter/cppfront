project(cppfront)
cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(cppfront source/cppfront.cpp)

# The test scripts are generated in two steps - configure to replace the
# variables, - geneated the configured output to replace the generator
# expressions.
configure_file(regression-tests/run-tests.bat.in
               ${CMAKE_BINARY_DIR}/run-tests.bat.in @ONLY)

file(
  GENERATE
  OUTPUT run-tests.bat
  INPUT ${CMAKE_BINARY_DIR}/run-tests.bat.in)

configure_file(regression-tests/run-tests.sh.in
               ${CMAKE_BINARY_DIR}/run-tests.sh.in @ONLY)

file(
  GENERATE
  OUTPUT run-tests.sh
  INPUT ${CMAKE_BINARY_DIR}/run-tests.sh.in
  FILE_PERMISSIONS
  OWNER_READ
  OWNER_WRITE
  OWNER_EXECUTE
  GROUP_READ
  GROUP_WRITE
  GROUP_EXECUTE
  WORLD_READ
  WORLD_EXECUTE)
