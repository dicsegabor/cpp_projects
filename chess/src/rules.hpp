#pragma once

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

const std::map<Type, int> figure_values = {
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

struct Coordinate
{
    std::size_t x, y;

    bool operator<(const Coordinate &other) const
    {
        if (x == other.x) return y < other.y;
        return x > other.x;
    }
};

typedef std::pair<Coordinate, Coordinate> Move;
