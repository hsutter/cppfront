# CPPFront CMake example

This is a simple demo of this fork's CMake integration. To build it,
first build cppfront. From this directory, run:

```
$ cmake -G Ninja -S .. -B build/cppfront -DCMAKE_BUILD_TYPE=Release
$ cmake --build build/cppfront
$ cmake --install build/cppfront --prefix _local
```

Now we'll configure this project to use the locally installed cppfront:

```
$ cmake -G Ninja -S . -B build/example -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_PREFIX_PATH=$PWD/_local
$ cmake --build build/example
$ ./build/example/main
$ cat xyxxy
Hello Fred with UFCS!
```
