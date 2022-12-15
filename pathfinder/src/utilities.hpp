#pragma once

#include <utility>
#include <vector>

typedef std::pair<int, int> Node, Dimensions, ConnectionType;

const std::pair<int, int> directions[4] = {
        {1,  0 }, // Right
        {0,  -1}, // Up
        {-1, 0 }, // Left
        {0,  1 }, // Down
    };

int hex_char_to_uint(char c);

std::vector<std::pair<int, int>> get_connections(char hexa, bool invert = false);

bool contains(const char *charset, const char c);