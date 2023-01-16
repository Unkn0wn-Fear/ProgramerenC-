cmake_minimum_required(VERSION 3.20)
project(C__Eindopdracht)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(C__Eindopdracht
        classes.cpp
        classes.hpp
        Main.cpp)
