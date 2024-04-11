cmake_minimum_required(VERSION 3.17)


add_executable(l09task03 
    main.cpp
    employee.cpp
    team.cpp
    ${LOCAL_INCLUDE}/employee.h
    ${LOCAL_INCLUDE}/task.h
    ${LOCAL_INCLUDE}/team.h)
    

target_include_directories(l09task03 PUBLIC ${LOCAL_INCLUDE})





