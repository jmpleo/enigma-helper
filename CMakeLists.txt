cmake_minimum_required(VERSION 3.18)

project(enigma)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W --std=c++11")

set(SOURCE_FILES main.cpp
                 perm.cpp
                 generator.cpp)

add_executable(enigma ${SOURCE_FILES})
