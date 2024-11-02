cmake_minimum_required(VERSION 3.10)
project(NostalgiaSandbox)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_subdirectory(Nostalgia)
add_subdirectory(Sandbox)