#!/bin/bash -e

echo -- Building project
cmake --build build-debug
echo -- Debugging project
gdb build-debug/Pathfinder