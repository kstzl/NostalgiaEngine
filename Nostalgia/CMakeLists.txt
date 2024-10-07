cmake_minimum_required(VERSION 3.10)
project(Nostalgia)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE NOSTALGIA_ENGINE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp
)

add_library(Nostalgia SHARED ${NOSTALGIA_ENGINE_SOURCES})

target_include_directories(Nostalgia PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glad)

target_link_libraries(Nostalgia glfw)
target_link_libraries(Nostalgia Glad)