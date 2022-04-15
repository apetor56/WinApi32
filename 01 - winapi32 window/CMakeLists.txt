cmake_minimum_required(VERSION 3.0.0)
project("winapi32 - window" VERSION 0.1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_compile_options(-std=c++17 -Wall -pedantic)

set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)

message("Start building target")
add_executable(WinMain ${SRC}/WinMain.cpp)