#pragma once

#include <utility>
#include <vector>
#include <algorithm>

typedef std::pair<int, int> Dir, Node;

// Directions in ther graph
const std::pair<int, int> dirs[4] = {
    {1,  0 }, // Right
    {0,  -1}, // Up
    {-1, 0 }, // Left
    {0,  1 }, // Down
};

int hex_char_to_uint(char c);

std::vector<std::pair<int, int>>
get_connections(char hexa, bool invert = false);

template <typename T> bool contains(std::vector<T> vec, T x) 
{
    return std::find(vec.begin(), vec.end(), x) != vec.end();
}

bool contains(const char *charset, const char c);