cmake_minimum_required(VERSION 3.17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(
        l07task02
        cpu.cpp
        disk.cpp
        gpu.cpp
        kbd.cpp
        ram.cpp
        main.cpp
        ${LOCAL_INCLUDE}/cpu.h
        ${LOCAL_INCLUDE}/disk.h
        ${LOCAL_INCLUDE}/gpu.h
        ${LOCAL_INCLUDE}/kbd.h
        ${LOCAL_INCLUDE}/ram.h
        ${LOCAL_INCLUDE}/commands.h)

target_include_directories(l07task02 PUBLIC ${LOCAL_INCLUDE})
