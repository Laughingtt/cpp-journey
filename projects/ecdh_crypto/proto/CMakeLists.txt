cmake_minimum_required(VERSION 3.9)
project(Proto)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
option(BUILD_PROTO_TEST "Set to ON to build tests" ON)
add_compile_options(-fPIC)


#-I
#include_directories(${PROJECT_SOURCE_DIR})

#message("sub before PROTO_SRC PATH is " ${PROTO_SRC})
## 定义src
#aux_source_directory(${PROJECT_SOURCE_DIR}/src PROTO_SRC)
#message("sub after PROTO_SRC PATH is " ${PROTO_SRC})

## protobuf
#find_package(Protobuf REQUIRED)
#message("Protobuf_INCLUDE_DIRS: ${Protobuf_INCLUDE_DIRS}")
#message("Protobuf_LIBRARIES: ${Protobuf_LIBRARIES}")
#include_directories(${Protobuf_INCLUDE_DIRS})


#  add test
if (BUILD_PROTO_TEST)
    message(STATUS "BUILD_PROTO_TEST defined: " ${BUILD_PROTO_TEST})
    add_executable(proto_test test.cpp "${PROTO_SRC}")
    target_link_libraries(proto_test ${Protobuf_LIBRARIES})
endif ()