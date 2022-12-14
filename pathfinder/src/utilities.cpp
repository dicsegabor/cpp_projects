#include "utilities.hpp"

#include <stdexcept>

unsigned int hex_char_to_uint(char c)
{
    if (!(('0' <= c && c <= '9') || ('A' <= c && c <= 'F') || ('a' <= c && c <= 'f')))
        throw std::invalid_argument(
            "The character with the code '" + std::to_string(c) +
            "' cannot be interpreted!"
        );

    // Convert hexa char to int, works with lower and uppercase letters
    return c > '9' ? (c > 'F' ? c - 87 : c - 55) : c - '0';
}

std::vector<std::pair<int, int>> get_connections(char hexa, bool invert)
{
    auto connection_type = hex_char_to_uint(hexa);

    if (invert) connection_type = 15 - connection_type;

    const std::pair<int, int> connection_types[4] = {
        {1,  0 }, // Right
        {0,  -1}, // Up
        {-1, 0 }, // Left
        {0,  1 }, // Down
    };

    // Iterating over the 4 bits, and adding appropriate connections
    std::vector<std::pair<int, int>> connections;
    for (int i = 0; i < 4; i++)
    {
        if (connection_type & 0b01) connections.push_back(connection_types[i]);
        connection_type = connection_type >> 1;
    }

    return connections;
}