cmake_minimum_required(VERSION 3.20)
project(thread_pool)

set(CMAKE_CXX_STANDARD 17)
message(PROJECT_SOURCE_DIR:${PROJECT_SOURCE_DIR})

find_package(OpenSSL REQUIRED)

message("OPENSSL_INCLUDE_DIR: ${OPENSSL_INCLUDE_DIR}")
message("OPENSSL_LIBRARIES: ${OPENSSL_LIBRARIES}")

include_directories(${PROJECT_SOURCE_DIR} ${OPENSSL_INCLUDE_DIR})
# 添加需要链接的库文件路径
link_libraries(${OPENSSL_LIBRARIES})

aux_source_directory(${PROJECT_SOURCE_DIR}/thread SRC)


add_executable(thread_pool main.cpp ${SRC})
