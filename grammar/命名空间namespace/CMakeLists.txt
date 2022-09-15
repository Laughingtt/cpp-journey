cmake_minimum_required(VERSION 3.10)
project(name_test)

set(CMAKE_CXX_STANDARD 14)

link_directories(${PROJECT_SOURCE_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}/include)
add_executable(name_test main.cpp)

# add lib
add_library(test_library STATIC lib/clal.cpp)


# find package
target_link_libraries(name_test libtest_library.a)
target_link_libraries(name_test libshard_test.dylib)
