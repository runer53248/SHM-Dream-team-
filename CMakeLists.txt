cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(SHM)

set(COMPILER_DEBUG_FLAGS -Wall -Werror -Wpedantic -Wextra -g -O0)
set(COMPILER_RELEASE_FLAGS -Wall -Werror -Wpedantic -Wextra -g0 -O3)

include_directories(include)
add_subdirectory(game)
add_subdirectory(test)
