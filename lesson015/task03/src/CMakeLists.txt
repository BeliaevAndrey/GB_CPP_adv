cmake_minimum_required(VERSION 3.17)

add_executable(
        l15task03 
        ${LOCAL_INCLUDE}/registry.h
        main.cpp)

target_include_directories(l15task03 PUBLIC ${LOCAL_INCLUDE})
