Unit tests
==========

The unit tests rely on `GNU/Make` as well as `bats`.

The following make targets are available:

   - all (builds all required binaries)
   - check (runs all checks)
   - clean (cleans up generated files and resets changes made on checked-in files)

Running all unit tests
----------------------
Simply run:

    $ make check

Prerequisites for running unit tests
------------------------------------
You'll need to have `make` and `bats` installed. Installing these are
out of scope for this document, but if you're on a deb-based system,
like Ubuntu, you might want to run:

    $ sudo apt install bats
    $ sudo apt install make

The Makefiles have been developed under GNU/Linux and will probably
not work on Windows, unless you use them under Cygwin.

Flagging negative unit tests as `passed`
---------------------------------------
The `regression-tests/` directory contains unit tests that are meant to
test negatively. In order for these `negative` unit tests to be
flagged as `passed`, the following simple flat file was created:

    regression-tests/negative_tests

The syntax for this file is:

    test_name expected_return_value

For examples, please look at the contents of the
`regression-tests/negative_tests` file. The `expected_return_value` is
the expected return value (0 to 255) of `cppfront`, for which the test
should be regarded as `passed`.

For tests, not listed in `regression-tests/negative_tests`, the
default `expected_return_value` is 0. In other words, if a test should
be regarded as `passed`, when `cppfront` returns 0, you would *not* need
to add an entry for it, in the `regression-tests/negative_tests` file.

Please stick to this simple syntax, as the parsing of this file is
very basic and fragile.

Adding unit tests
-----------------
Due to the generic way in which the unit tests get generated, no extra
work needs to be done to add unit tests to the `regression-tests/`
directory. Simply add another mixed-\*.cpp2 or pure2-\*.cpp2 file to the
`regression-tests/` directory. Refer to the previous chapter, if you
need to flag a failing test as 'passed'.

Cleaning up
-----------
In order to get rid of all build and test artifacts, simply run:

    $ make clean

Building cppfront
----------------
Simply run:

    $ make

The cppfront binary will be built in the source/ directory.

Notes
-----
In order to make the Makefiles work under as many platforms as
possible, one should contemplate, using `automake` or maybe `cmake`.
