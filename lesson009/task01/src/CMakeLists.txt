cmake_minimum_required(VERSION 3.17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(
    l09task01
    main.cpp
    ??.cpp
    ${LOCAL_INCLUDE}/??.h
    ${LOCAL_INCLUDE}/??.h)

target_include_directories(l09task01 PUCLIC ${LOCAL_INCLUDE})