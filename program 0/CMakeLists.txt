cmake_minimum_required(VERSION 3.8)
project(program_0)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES TestDriver.cpp myVector.h)
add_executable(program_0 ${SOURCE_FILES})