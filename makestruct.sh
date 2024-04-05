#! /usr/bin/env bash

echo $1 $2

if [ !$1 ];
then
    mkdir -p $1
fi


mkdir $1/include
mkdir $1/src


touch $1/CMakeLists.txt

echo "cmake_minimum_required(VERSION 3.17)" >> $1/CMakeLists.txt
echo "project(\"Lesson XX, task XX\" VERSION 1.0)" >> $1/CMakeLists.txt
echo    >> $1/CMakeLists.txt
echo "set(CMAKE_CXX_STANDARD 14)" >> $1/CMakeLists.txt
echo "set(LOCAL_INCLUDE \${CMAKE_SOURCE_DIR}/include)" >> $1/CMakeLists.txt
echo    >> $1/CMakeLists.txt
echo "set(CMAKE_RUNTIME_OUTPUT_DIRECTORY \${CMAKE_BINARY_DIR}/bin)" >> $1/CMakeLists.txt
echo "set(CMAKE_VERBOSE_MAKEFILE)" >> $1/CMakeLists.txt
echo    >> $1/CMakeLists.txt
echo "add_subdirectory(src)" >> $1/CMakeLists.txt

touch $1/src/CMakeLists.txt

echo "cmake_minimum_required(VERSION 3.17)" >> $1/src/CMakeLists.txt
echo "set(CMAKE_RUNTIME_OUTPUT_DIRECTORY \${CMAKE_BINARY_DIR}/bin)" >> $1/src/CMakeLists.txt
echo  >> $1/src/CMakeLists.txt
echo "add_executable(lXXtaskXX" >> $1/src/CMakeLists.txt
echo "        ??.cpp" >> $1/src/CMakeLists.txt
echo "        ??.cpp" >> $1/src/CMakeLists.txt
echo "        main.cpp" >> $1/src/CMakeLists.txt
echo "        \${LOCAL_INCLUDE}/??.h" >> $1/src/CMakeLists.txt
echo "        \${LOCAL_INCLUDE}/??.h)" >> $1/src/CMakeLists.txt
echo  >> $1/src/CMakeLists.txt
echo "target_include_directories(l08task02 PUBLIC \${LOCAL_INCLUDE})" >> $1/src/CMakeLists.txt


touch $1/src/main.cpp
