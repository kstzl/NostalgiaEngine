cmake_minimum_required(VERSION 3.10)
project(Glad)

set(CMAKE_CXX_STANDARD 20)

add_library(Glad STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/glad.c)

target_include_directories(Glad PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
)