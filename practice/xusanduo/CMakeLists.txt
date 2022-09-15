cmake_minimum_required(VERSION 3.10)
project(xusanduo)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2 -Wall")

include_directories(${PROJECT_SOURCE_DIR}/include)

# 将src中的源文件添加到SRC这个变量中去
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)

# 将源文件一一加入可执行文件
add_executable(Demo main.cpp ${SRC})