cmake_minimum_required(VERSION 3.1)

project("pybind_example")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2 -Wall")

include_directories("/usr/local/include"
        ${PROJECT_SOURCE_DIR}/ml/example/include)

include(${PROJECT_SOURCE_DIR}/test.cmake)

add_subdirectory(extern/pybind11)
pybind11_add_module(algo_lib python/example.cpp)