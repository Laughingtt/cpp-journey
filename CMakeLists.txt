cmake_minimum_required(VERSION 3.9)
project(CPP-BasicUsage)

message(PROJECT_SOURCE_DIR:${PROJECT_SOURCE_DIR})

option(BUILD_SUB "Set to ON to build SUB" ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2 -Wall")


#  add SUB
if (BUILD_SUB)
    add_subdirectory(tools/thread_pool)
    add_subdirectory(leetcode)
    add_subdirectory(projects/light_particle)
endif()