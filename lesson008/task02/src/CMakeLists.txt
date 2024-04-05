cmake_minimum_required(VERSION 3.17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(l08task02
        phone.cpp
        phonenumber.cpp
        main.cpp
        ${LOCAL_INCLUDE}/phone.h
        ${LOCAL_INCLUDE}/phonenumber.h)

target_include_directories(l08task02 PUBLIC ${LOCAL_INCLUDE})
