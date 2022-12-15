cmake_minimum_required(VERSION 3.20)
project(main)

set(CMAKE_CXX_STANDARD 17)

message(PROJECT_SOURCE_DIR:${PROJECT_SOURCE_DIR})
message(PROJECT_NAME:${PROJECT_NAME})
message(CMAKE_PROJECT_NAME:${CMAKE_PROJECT_NAME})


add_executable(main main.cpp include/master.cpp)
target_link_libraries(main sub_lib)