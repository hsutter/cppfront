function(_cppfront_unique_name base hash outvar)
    string(LENGTH "${hash}" len)
    foreach (i RANGE 0 "${len}")
        string(SUBSTRING "${hash}" 0 "${i}" uniq)
        if (uniq)
            set(name "${base}-${uniq}")
        else ()
            set(name "${base}")
        endif ()
        get_property(name_used GLOBAL PROPERTY "cppfront/names/${name}" SET)
        if (NOT name_used)
            set("${outvar}" "${name}" PARENT_SCOPE)
            set_property(GLOBAL PROPERTY "cppfront/names/${name}" 1)
            return()
        endif ()
    endforeach ()
    # This should be impossible, unless caching in _cppfront_generate_source
    # is broken.
    message(FATAL_ERROR "Could not compute a unique name using ${base} and ${hash}")
endfunction()

function(_cppfront_generate_source src out)
    # TODO: there's probably something nicer/more user-friendly to be
    #   done here, but it's maybe not worth thinking about until cppfront's
    #   command line improves.

    file(REAL_PATH "${src}" src)
    string(SHA256 src_hash "${src}")

    get_property(out_file GLOBAL PROPERTY "cppfront/out_file/${src_hash}")
    if (out_file)
        set("${out}" "${out_file}" PARENT_SCOPE)
        return()
    endif ()

    cmake_path(GET src STEM original_stem)
    _cppfront_unique_name("${original_stem}" "${src_hash}" basename)

    # assume no SHA256 collisions
    file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/_cppfront/")
    set(src_file "${CMAKE_BINARY_DIR}/_cppfront/${basename}.cpp2")
    set(out_file "${CMAKE_BINARY_DIR}/_cppfront/${basename}.cpp")

    add_custom_command(
        OUTPUT "${out_file}"
        COMMAND "${CMAKE_COMMAND}" -E copy "${src}" "${src_file}"
        COMMAND cppfront::cppfront "${basename}.cpp2" ${CPPFRONT_FLAGS}
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/_cppfront"
        DEPENDS "${src}" cppfront::cppfront
        VERBATIM
    )

    set_property(GLOBAL PROPERTY "cppfront/out_file/${src_hash}" "${out_file}")
    set("${out}" "${out_file}" PARENT_SCOPE)
endfunction()

function(cppfront_enable)
    cmake_parse_arguments(PARSE_ARGV 0 ARG "" "" "TARGETS")

    foreach (tgt IN LISTS ARG_TARGETS)
        get_property(sources TARGET "${tgt}" PROPERTY SOURCES)
        list(FILTER sources INCLUDE REGEX "\\.cpp2$")

        if (sources)
            target_link_libraries("${tgt}" PRIVATE cppfront::cpp2util)
        endif ()

        foreach (src IN LISTS sources)
            _cppfront_generate_source("${src}" out_path)
            target_sources("${tgt}" PRIVATE "${out_path}")
        endforeach ()
    endforeach ()
endfunction()

function(_cppfront_enable_dir)
    get_property(targets DIRECTORY . PROPERTY BUILDSYSTEM_TARGETS)
    cppfront_enable(TARGETS ${targets})
endfunction()

if (NOT CPPFRONT_NO_MAGIC)
    if (NOT _CPPFRONT_MAGIC_DIR)
        set(_CPPFRONT_MAGIC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
    endif ()
    message(VERBOSE "Enabling cppfront for all targets in ${_CPPFRONT_MAGIC_DIR}")
    cmake_language(DEFER DIRECTORY "${_CPPFRONT_MAGIC_DIR}" CALL _cppfront_enable_dir)
endif ()
