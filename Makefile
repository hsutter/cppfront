#  Copyright 2022-2025 Herb Sutter
#  SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
#  
#  Part of the Cppfront Project, under the Apache License v2.0 with LLVM Exceptions.
#  See https://github.com/hsutter/cppfront/blob/main/LICENSE for license information.
#
#  This Makefile is strictly optional and is just a convenience for building cppfront.
#  You can also build cppfront by running the cppfront.cpp source file through your 
#  C++ compiler in the normal manner.

all: cppfront.exe source/reflect.h include/cpp2regex.h

CXX ?= g++
CPPFRONT ?= ./cppfront.exe
CFLAGS ?=
REGRESS_LABEL ?= regress
REGRESS_STD ?= c++2b

CFLAGS += -Wall -Werror -Wextra -Wpedantic

ifeq (${DEBUG},1)
CFLAGS += -g
endif
ifeq (${RELEASE},1)
CFLAGS += -O3
endif
ifeq (${PROFILE},1)
CFLAGS += -pg
endif
ifeq (${SANITIZE},1)
CFLAGS += -fsanitize=address -fsanitize=undefined
endif
ifeq (${COVERAGE},1)
CFLAGS += --coverage
endif

cppfront.exe: source/cppfront.cpp source/common.h source/cpp2regex.h include/cpp2regex.h source/cpp2util.h include/cpp2util.h source/io.h source/lex.h source/parse.h source/reflect.h source/sema.h source/to_cpp1.h
	${CXX} -std=c++20 -o cppfront.exe -Iinclude ${CFLAGS} source/cppfront.cpp

include/cpp2regex.h: include/cpp2regex.h2
	${CPPFRONT} include/cpp2regex.h2 -o include/cpp2regex.h

source/reflect.h: source/reflect.h2
	${CPPFRONT} source/reflect.h2 -o source/reflect.h

regress: cppfront.exe
	cd regression-tests && \
	bash ./run-tests.sh -e ../cppfront.exe -c ${CXX} -l ${REGRESS_LABEL} -s ${REGRESS_STD}

clean:
	rm -f cppfront.exe
