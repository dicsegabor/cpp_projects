cmake_minimum_required(VERSION 3.10)

project(DemocraticChess VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(DemocraticChess main.c board.c field.c graphics.cpp control.cpp)