#pragma once

#include <utility>
#include <vector>

unsigned int hex_char_to_uint(char c);

std::vector<std::pair<int, int>> get_connections(char hexa, bool invert = false);
