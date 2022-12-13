cmake_minimum_required(VERSION 3.10)

project(Pathfinder)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Pathfinder main.cpp graph.cpp bfs.cpp)