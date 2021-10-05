cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(SHM)

include_directories(include)
add_subdirectory(game)
add_subdirectory(test)
