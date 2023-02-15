cmake_minimum_required(VERSION 3.9)

project(secure_nn)

add_executable(secure_nn_test main.cpp core.cpp core.h)


# link xtensor
find_package(xtensor REQUIRED)
target_include_directories(secure_nn_test PUBLIC ${xtensor_INCLUDE_DIRS})
target_link_libraries(secure_nn_test PUBLIC xtensor)