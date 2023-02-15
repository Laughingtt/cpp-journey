
cmake_minimum_required(VERSION 3.17)

project(xtensor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2 -Wall")

include_directories(.)
add_executable(xtensor-run xtensor_test.cpp)

find_package(xtensor REQUIRED)
target_include_directories(xtensor-run PUBLIC ${xtensor_INCLUDE_DIRS})
target_link_libraries(xtensor-run PUBLIC xtensor)

