cmake_minimum_required(VERSION 3.20)
project(proj4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(proj4
        Date.cpp
        Date.h
        main.cpp)
