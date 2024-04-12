cmake_minimum_required(VERSION 3.17)
project("Lesson 14, task 01" VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

set(JSON_BuildTests OFF CACHE INTERNAL "")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)

FetchContent_MakeAvailable(json)

add_executable(l14task02 main.cpp)

target_link_libraries(l14task02 PRIVATE nlohmann_json::nlohmann_json)
