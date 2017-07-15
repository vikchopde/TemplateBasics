cmake_minimum_required(VERSION 2.8)
project(templates_basics)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp ConstExpr.h)
add_executable(templates_basics ${SOURCE_FILES})
