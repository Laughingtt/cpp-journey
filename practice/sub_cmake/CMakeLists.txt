cmake_minimum_required(VERSION 3.20)
project(cmake_dir)

set(CMAKE_CXX_STANDARD 17)

message(PROJECT_SOURCE_DIR:${PROJECT_SOURCE_DIR})
message(PROJECT_NAME:${PROJECT_NAME})
message(CMAKE_PROJECT_NAME:${CMAKE_PROJECT_NAME})

# 导入当前文件夹为头文件
include_directories(.)


add_subdirectory(sub)
add_subdirectory(main)
