# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Define the project name and specify C++ standard
project(Simplify VERSION 1.0 LANGUAGES CXX)

enable_language(CXX)

# Set the C++ standard
#set(CMAKE_CXX_COMPILER "/user/bin/g++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

file(GLOB all_SRC  "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Add executable
add_executable(test ${all_SRC})