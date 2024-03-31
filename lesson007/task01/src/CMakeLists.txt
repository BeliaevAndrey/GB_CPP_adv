cmake_minimum_required(VERSION 3.17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(
  l07task01
  main.cpp
  ${MY_INCLUDE_DIR}/operations.h
  ${MY_INCLUDE_DIR}/point.h
  )

target_include_directories(l07task01 PUBLIC ${MY_INCLUDE_DIR})
