# cppfront/self_hosting — Purpose and separation

This directory contains small, iterative cpp2 modules related to cppfront's
self-hosting work. Two different concepts use the phrase "self-hosting" in
this repository; it's important not to conflate them.

1) "cppfront self-hosting" (compiler-level): the cpp2/cppfront compiler and
   transform pipeline that can compile/transform cpp2 sources (the compiler
   bootstraps or contains its own transforms). Files that belong to this
   domain are kept here under `cppfront/self_hosting/`.

2) "Oroboros hosting/self-hosting" (application-level): Oroboros runtime
   components that host protocols, services, or storage engines (IPFS,
   CouchDB wrappers, densified runtime). Those remain in the Oroboros tree
   (e.g., `src/`, `prev/`), and must not contain compiler-internal cpp2
   modules.

Guidelines
- Compiler/cpp2 modules go under `cppfront/self_hosting/` only.
- Runtime/oroboros hosting code stays in `src/`, `prev/`, or `cppfront/` as
  appropriate but never mixes with the compiler stubs.
- Use this README as the canonical place to document new cpp2 modules for the
  cppfront bootstrap. Keep these modules hermetic and small until they're
  promoted into the compiler core.

## Development Notes

- Build the demo using the main cppfront Makefile in the parent directory
- Test coverage is maintained through the main test suite in `tests/`
- All modules follow cpp2 syntax and compile to standard C++
