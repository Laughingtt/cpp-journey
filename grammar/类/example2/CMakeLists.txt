cmake_minimum_required(VERSION 3.20)
project(learning)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2 -Wall")

include_directories("include")

add_executable(learning main.cpp src/Cube.cpp)
