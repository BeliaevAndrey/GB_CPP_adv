cmake_minimum_required(VERSION 3.17)
project("Lesson 08, task 01" VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(LOCAL_INCLUDE ${CMAKE_SOURCE_DIR}/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_VERBOSE_MAKEFILE)

add_subdirectory(src)
