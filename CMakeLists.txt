cmake_minimum_required(VERSION 3.6)
project(lab_bmplib)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES shapes.cpp bmplib.cpp)
add_executable(lab_bmplib ${SOURCE_FILES})
