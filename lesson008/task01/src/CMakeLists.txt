cmake_minimum_required(VERSION 3.17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(
        l08task01
        album.cpp
        player.cpp
        track.cpp
        main.cpp
        ${LOCAL_INCLUDE}/album.h
        ${LOCAL_INCLUDE}/track.h
        ${LOCAL_INCLUDE}/player.h)

target_include_directories(l08task01 PUBLIC ${LOCAL_INCLUDE})
