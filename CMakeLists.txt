cmake_minimum_required(VERSION 3.30)
project(MAE_B11)

set(CMAKE_CXX_STANDARD 11)
set(INCLUDE ./src/class)

include_directories(${INCLUDE})

add_executable(MAE_B11
        src/main.cpp
        src/class/sqrMatrix.h
        src/class/sqrMatrix.cpp)
