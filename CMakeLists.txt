cmake_minimum_required(VERSION 3.10)

project(cpp-core)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(cpp-core src/logging.cpp)

target_include_directories(cpp-core PUBLIC src)

