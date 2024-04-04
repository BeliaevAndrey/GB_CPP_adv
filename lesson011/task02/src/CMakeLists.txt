cmake_minimum_required(VERSION 3.17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(
    l11task01
    main.cpp
    dog.cpp
    talent.cpp
    animal.cpp
    cat.cpp
    ${LOCAL_INCLUDE}/dog.h
    ${LOCAL_INCLUDE}/animal.h
    ${LOCAL_INCLUDE}/talent.h
    ${LOCAL_INCLUDE}/cat.h
    )

target_include_directories(l11task01 PUBLIC ${LOCAL_INCLUDE})
