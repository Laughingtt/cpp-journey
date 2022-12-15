cmake_minimum_required(VERSION 3.20)
project(sub)

set(CMAKE_CXX_STANDARD 17)
message(PROJECT_SOURCE_DIR:${PROJECT_SOURCE_DIR})
message(PROJECT_NAME:${PROJECT_NAME})
message(CMAKE_PROJECT_NAME:${CMAKE_PROJECT_NAME})
message(cmake_dir_SOURCE_DIR:${cmake_dir_SOURCE_DIR})

# 为library 添加导入头文件
add_library(sub_lib include/test.cpp)
target_include_directories(sub_lib
        PUBLIC ${PROJECT_SOURCE_DIR}/include
        )

