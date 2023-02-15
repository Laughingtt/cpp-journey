
# compile cmd
# mkdir build && cd build && cmake -DOPENSSL_ROOT_DIR=/usr/local/opt/openssl/ -DOPENSSL_LIBRARIES=/usr/local/opt/openssl/lib/ ..

cmake_minimum_required(VERSION 3.9)
project(leetcode)
include_directories(${PROJECT_SOURCE_DIR}/include)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O2 -Wall")
add_compile_options("-std=c++11")
add_executable("leetcode" src/链表/删除链表的倒数第N个节点.cpp)