
cmake_minimum_required(VERSION 3.17)

project(light_particle)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2 -Wall")

include_directories(.)

add_subdirectory(modules/io)
add_subdirectory(modules/protocol/secure_nn)

add_executable(out 大整数mpc.cpp)