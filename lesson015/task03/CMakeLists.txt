cmake_minimum_required(VERSION 3.17)
project("Lesson 15, task 03" VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

set(LOCAL_INCLUDE ${CMAKE_SOURCE_DIR}/include)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)
