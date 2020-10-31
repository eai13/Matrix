cmake_minimum_required(VERSION 3.0.0)

project(TEST)

add_library(MatrixLib STATIC ../src/MatrixLib.cpp ../include/MatrixLib.h)

add_executable(TEST Test.cpp)

target_link_libraries(TEST PRIVATE MatrixLib)