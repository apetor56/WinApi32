cmake_minimum_required(VERSION 3.0.0)
project("winapi32 - window" VERSION 0.1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_compile_options(-std=c++17 -Wall -pedantic  -I./include -I./include)

# set source files path
set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# set include file path
set(INCLUDE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include)

message("Start building target")

# create the exe file
add_executable(WinMain
    ${SRC}/WinMain.cpp
    ${SRC}/Window.cpp
)

# add to include path to WinMain target,
# always after add_executable/add_library
target_include_directories(WinMain PRIVATE ${INCLUDE_FILES})