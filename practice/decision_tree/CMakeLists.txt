cmake_minimum_required(VERSION 3.17)
project(decison_tree)
set(CMAKE_CXX_STANDARD 14)
include_directories(${PROJECT_SOURCE_DIR}/include)


aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)
message(${SRC})

add_executable(main ${PROJECT_SOURCE_DIR}/main.cpp ${SRC})