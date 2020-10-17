cmake_minimum_required(VERSION 2.8)
add_definitions("-Wall -std=c++0x")
project(detect CXX)
set("1.0.0")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)
include_directories(./src/)
add_executable(detect ./src/main.cpp
		      ./src/Detect/detect.cpp
		      ./src/Detect/option.cpp)
