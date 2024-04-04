cmake_minimum_required(VERSION 3.17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(
    l11task02
    main.cpp
    ${LOCAL_INCLUDE}/dog.h
    )

target_include_directories(l11task02 PUBLIC ${LOCAL_INCLUDE})
