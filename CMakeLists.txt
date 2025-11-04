cmake_minimum_required(VERSION 3.31)
project(cpplabs LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wno-c++20-extensions)
    add_compile_options(-std=c++20)
    add_compile_options(-Wno-unknown-warning-option)
    add_compile_options(-Wno-c++20-extensions)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if (MSVC)
    add_compile_options(/W4 /permissive-)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(SUBMITTED_LABS
        1_1
        1_2
        1_3
        1_4
        1_5
        1_6
        2_1_1
        2_1_2
        2_2
        2_3
        2_4
        2_5
        2_6
        3_1
        4_1
        4_3
        5_4
        6_1
)

file(GLOB LAB_SOURCES "*.cpp")

foreach(src ${LAB_SOURCES})
    get_filename_component(target_name ${src} NAME_WE)
    add_executable(${target_name} ${src})

    list(FIND SUBMITTED_LABS ${target_name} is_submitted)
    if (NOT is_submitted EQUAL -1)
        message(STATUS "✅ Лабораторная ${target_name} — СДАНА")
        set_target_properties(${target_name} PROPERTIES FOLDER "✅ Submitted")
    else()
        message(STATUS "🕒 Лабораторная ${target_name} — ЕЩЁ НЕ СДАНА")
        set_target_properties(${target_name} PROPERTIES FOLDER "🕒 Pending")
    endif()
endforeach()
