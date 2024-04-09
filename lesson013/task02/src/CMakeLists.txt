cmake_minimum_required(VERSION 3.17)

add_executable(l13task02
    main.cpp
    dog.cpp
    toy.cpp
    ${LOCAL_INCLUDE}/dog.h
    ${LOCAL_INCLUDE}/toy.h
    )

target_include_directories(l13task02 PUBLIC ${LOCAL_INCLUDE})
