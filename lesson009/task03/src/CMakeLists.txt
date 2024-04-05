cmake_minimum_required(VERSION 3.17)

add_executable(l09task03
    main.cpp
    team.cpp
    group.cpp
    employee.cpp
    manager.cpp
    task.cpp
    ${LOCAL_INCLUDE}/team.h
    ${LOCAL_INCLUDE}/group.h
    ${LOCAL_INCLUDE}/employee.h
    ${LOCAL_INCLUDE}/manager.h
    ${LOCAL_INCLUDE}/task.h)

target_include_directories(l09task03 PUBLIC ${LOCAL_INCLUDE})





