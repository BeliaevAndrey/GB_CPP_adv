cmake_minimum_required(VERSION 3.17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(l08task03
        window.cpp
        display.cpp
        position.cpp
        main.cpp
        ${LOCAL_INCLUDE}/position.h
        ${LOCAL_INCLUDE}/display.h
        ${LOCAL_INCLUDE}/window.h)

target_include_directories(l08task03 PUBLIC ${LOCAL_INCLUDE})
