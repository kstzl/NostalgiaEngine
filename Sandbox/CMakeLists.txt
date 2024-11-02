cmake_minimum_required(VERSION 3.10)
project(Sandbox)

set(CMAKE_CXX_STANDARD 20)

add_executable(Sandbox
    src/main.cpp
)

target_link_libraries(Sandbox PRIVATE Nostalgia)