cmake_minimum_required(VERSION 3.17)

add_executable(l13task02
    main.cpp
    shared_ptr_toy.cpp
    ${LOCAL_INCLUDE}/toy.h
    ${LOCAL_INCLUDE}/shared_ptr_toy.h
    )

target_include_directories(l13task02 PUBLIC ${LOCAL_INCLUDE})
