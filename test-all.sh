#!/bin/bash

set -e

export CMAKE_CXX_COMPILER_LAUNCHER=ccache

rm -rf build _local

cmake -S . -B build/cppfront -DCMAKE_BUILD_TYPE=Release \
  "-DCMAKE_INSTALL_PREFIX=$PWD/_local"
cmake --build build/cppfront --target install

cmake -S regression-tests -B build/regression-tests \
  -DCMAKE_BUILD_TYPE=Release "-DCMAKE_PREFIX_PATH=$PWD/_local"
cmake --build build/regression-tests

(
  cd build/regression-tests
  ctest --output-on-failure -j "$(nproc)"
)

rm -rf build _local
