#pragma once

#include <cstddef>
#include <map>

enum class Type
{
    Pawn,
    Bishop,
    Knight,
    Rook,
    Queen,
    King
};

const std::map<char, Type> type_chars = {
    {'P', Type::Pawn  },
    {'B', Type::Bishop},
    {'N', Type::Knight},
    {'R', Type::Rook  },
    {'Q', Type::Queen },
    {'K', Type::King  }
};

const std::map<Type, int> type_values = {
    {Type::Pawn,   1  },
    {Type::Bishop, 3  },
    {Type::Knight, 3  },
    {Type::Rook,   5  },
    {Type::Queen,  8  },
    {Type::King,   100}
};

enum Color
{
    Black = 30,
    Red,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan,
    White,
};

const std::map<char, Color> color_chars = {
    {'B', Color::Black},
    {'W', Color::White},
};

struct Coordinate
{
    std::size_t x, y;

    Coordinate(std::size_t x, std::size_t y) : x(x), y(y) {}

    bool operator<(const Coordinate &other) const
    {
        if (x == other.x) return y < other.y;
        return x > other.x;
    }
};

typedef std::pair<Coordinate, Coordinate> Move;
