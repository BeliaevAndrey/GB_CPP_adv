cmake_minimum_required(VERSION 3.17)

add_executable(l09task02
    main.cpp
    figure.cpp
    circle.cpp
    triangle.cpp
    rectangle.cpp
    square.cpp
    ${LOCAL_INCLUDE}/figure.h
    ${LOCAL_INCLUDE}/circle.h
    ${LOCAL_INCLUDE}/triangle.h
    ${LOCAL_INCLUDE}/rectangle.h
    ${LOCAL_INCLUDE}/square.h
    )

target_include_directories(l09task02 PUCLIC ${LOCAL_INCLUDE})
