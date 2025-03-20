cmake_minimum_required(VERSION 3.30)
project(MAE_B11)

set(CMAKE_CXX_STANDARD 11)
set(INCLUDE ./src/class)

include_directories(${INCLUDE})

add_executable(MAE_B11 main2.temp
        src/main.cpp
        src/class/matrix.h
        src/class/matrix.cpp)
