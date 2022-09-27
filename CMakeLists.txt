cmake_minimum_required(VERSION 3.23)
project(
    cppfront
    LANGUAGES CXX
    VERSION 0.1.0
)

##
# Project options

include(CMakeDependentOption)

cmake_dependent_option(
    CPPFRONT_INSTALL_RULES "Include install rules for cppfront" "${PROJECT_IS_TOP_LEVEL}"
    "NOT CMAKE_SKIP_INSTALL_RULES" OFF
)

cmake_dependent_option(
    CPPFRONT_NO_SYSTEM "Do not mark cpp2 runtime headers as SYSTEM" OFF
    "NOT PROJECT_IS_TOP_LEVEL" ON
)
mark_as_advanced(CPPFRONT_NO_SYSTEM)

##
# Compute option-derived constants

if (CPPFRONT_NO_SYSTEM)
    set(_cppfront_SYSTEM "")
else ()
    set(_cppfront_SYSTEM SYSTEM)
endif ()

##
# Target definition for cppfront executable

add_executable(cppfront_cppfront source/cppfront.cpp)
add_executable(cppfront::cppfront ALIAS cppfront_cppfront)
set_target_properties(
    cppfront_cppfront
    PROPERTIES
    OUTPUT_NAME cppfront
    EXPORT_NAME cppfront
)

target_compile_features(cppfront_cppfront PRIVATE cxx_std_20)
target_sources(
    cppfront_cppfront
    PRIVATE
    FILE_SET HEADERS
    BASE_DIRS source
    FILES source/common.h source/lex.h source/load.h source/parse.h source/sema.h
)

##
# Target definition for cpp2util runtime library

add_library(cppfront_cpp2util INTERFACE)
add_library(cppfront::cpp2util ALIAS cppfront_cpp2util)
set_target_properties(cppfront_cpp2util PROPERTIES EXPORT_NAME cpp2util)

target_compile_features(cppfront_cpp2util INTERFACE cxx_std_20)
target_include_directories(
    cppfront_cpp2util ${_cppfront_SYSTEM} INTERFACE "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
)
target_sources(
    cppfront_cpp2util
    INTERFACE
    FILE_SET HEADERS
    BASE_DIRS include
    FILES include/cpp2util.h
)

##
# Enable cpp2 autodetection for add_subdirectory users

if (NOT PROJECT_IS_TOP_LEVEL)
    get_directory_property(_CPPFRONT_MAGIC_DIR PARENT_DIRECTORY)
    include(cmake/CppfrontHelpers.cmake)
endif ()

##
# Installation and CMake packaging logic

if (CPPFRONT_INSTALL_RULES)
    include(GNUInstallDirs)
    include(CMakePackageConfigHelpers)

    set(CPPFRONT_INSTALL_CMAKEDIR "${CMAKE_INSTALL_DATADIR}/cmake/cppfront"
        CACHE STRING "Install location for cppfront's platform-independent CMake files")

    set(CPPFRONT_INSTALL_EXE_CMAKEDIR "${CMAKE_INSTALL_LIBDIR}/cmake/cppfront-exe"
        CACHE STRING "Install location for cppfront's platform-specific CMake files")

    mark_as_advanced(CPPFRONT_INSTALL_CMAKEDIR CPPFRONT_INSTALL_EXE_CMAKEDIR)

    ##
    # Install rules for cppfront executable (which is naturally platform
    # dependent)

    install(
        TARGETS cppfront_cppfront
        EXPORT cppfront-exe-targets
        COMPONENT cppfront
    )

    install(
        EXPORT cppfront-exe-targets
        DESTINATION "${CPPFRONT_INSTALL_EXE_CMAKEDIR}"
        NAMESPACE cppfront::
        COMPONENT cppfront
    )

    configure_package_config_file(
        cmake/cppfront-exe-config.cmake.in
        cmake/cppfront-exe-config.cmake
        INSTALL_DESTINATION "${CPPFRONT_INSTALL_EXE_CMAKEDIR}"
        PATH_VARS CMAKE_INSTALL_BINDIR
    )

    write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/cmake/cppfront-exe-config-version.cmake"
        COMPATIBILITY ExactVersion
        ARCH_INDEPENDENT  # to allow finding host executables in cross-builds
    )

    install(
        FILES
        "${CMAKE_CURRENT_BINARY_DIR}/cmake/cppfront-exe-config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake/cppfront-exe-config-version.cmake"
        DESTINATION "${CPPFRONT_INSTALL_EXE_CMAKEDIR}"
        COMPONENT cppfront
    )

    ##
    # Install rules for cppfront CMake helpers and runtime headers,
    # which are platform-independent

    install(
        TARGETS cppfront_cpp2util
        EXPORT cppfront-targets
        FILE_SET HEADERS
        COMPONENT cppfront
    )
    install(
        EXPORT cppfront-targets
        DESTINATION "${CPPFRONT_INSTALL_CMAKEDIR}"
        NAMESPACE cppfront::
        COMPONENT cppfront
    )

    configure_package_config_file(
        cmake/cppfront-config.cmake.in
        cmake/cppfront-config.cmake
        INSTALL_DESTINATION "${CPPFRONT_INSTALL_CMAKEDIR}"
    )

    write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/cmake/cppfront-config-version.cmake"
        COMPATIBILITY ExactVersion
        ARCH_INDEPENDENT
    )

    install(
        FILES
        "${CMAKE_CURRENT_BINARY_DIR}/cmake/cppfront-config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake/cppfront-config-version.cmake"
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/CppfrontHelpers.cmake"
        DESTINATION "${CPPFRONT_INSTALL_CMAKEDIR}"
        COMPONENT cppfront
    )
endif ()
