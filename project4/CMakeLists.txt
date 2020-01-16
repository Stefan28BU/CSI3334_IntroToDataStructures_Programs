cmake_minimum_required(VERSION 3.8)
project(project4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp myQueue.h myList.h)
add_executable(project4 ${SOURCE_FILES})