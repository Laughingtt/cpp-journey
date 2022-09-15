cmake_minimum_required(VERSION 3.9)
project(CPP-BasicUsage)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2 -Wall")


add_executable(main "main.cpp")