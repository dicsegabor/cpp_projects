#!/bin/bash -e

echo -- Building project
cmake --build build-debug
echo -- Running project
gdb build-debug/Pathfinder