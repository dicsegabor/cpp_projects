#!/bin/bash -e

echo -- Building project
cmake --build debug
echo -- Debugging project
gdb build-debug/Pathfinder