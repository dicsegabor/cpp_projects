cmake_minimum_required(VERSION 3.10)

project(Chess VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Chess main.cpp board.cpp field.cpp figure.cpp graphics.cpp other.cpp)