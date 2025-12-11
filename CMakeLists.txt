cmake_minimum_required(VERSION 3.20)
project(algorithm_examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

file(GLOB_RECURSE CPP_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/cpp/*.cpp"
)

if(NOT CPP_SOURCES)
    message(FATAL_ERROR "No .cpp files were found under cpp/")
endif()

list(SORT CPP_SOURCES)

function(source_contains_main source_path result_var)
    file(STRINGS "${source_path}" main_candidates REGEX "[^A-Za-z0-9_]main\\s*\\(" LIMIT_COUNT 1)
    if(main_candidates)
        set(${result_var} TRUE PARENT_SCOPE)
    else()
        set(${result_var} FALSE PARENT_SCOPE)
    endif()
endfunction()

function(add_exec_for_source source_path)
    cmake_path(RELATIVE_PATH source_path BASE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" OUTPUT_VARIABLE rel_path)

    string(MAKE_C_IDENTIFIER "${rel_path}" target_name)
    if(target_name STREQUAL "")
        string(SHA1 hash "${rel_path}")
        string(SUBSTRING "${hash}" 0 8 target_name)
        string(PREPEND target_name "target_")
    endif()

    if(NOT target_name MATCHES "^[A-Za-z_]")
        string(PREPEND target_name "t_")
    endif()

    set(base_name "${target_name}")
    set(counter 2)
    while(TARGET "${target_name}")
        set(target_name "${base_name}_${counter}")
        math(EXPR counter "${counter} + 1")
    endwhile()

    if(source_path MATCHES "/build/")
        message(STATUS "Skipping ${rel_path} (inside build directory)")
        return()
    endif()

    source_contains_main("${source_path}" has_main)
    if(NOT has_main)
        message(STATUS "Skipping ${rel_path} (no main function found)")
        return()
    endif()

    add_executable("${target_name}" "${source_path}")
    message(STATUS "Added target ${target_name} -> ${rel_path}")
endfunction()

foreach(src IN LISTS CPP_SOURCES)
    add_exec_for_source("${src}")
endforeach()
