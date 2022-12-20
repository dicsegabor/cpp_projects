#pragma once

#include <cstddef>
#include <map>
#include <utility>
#include <vector>

#include "field.hpp"


class Board
{
    const size_t WIDTH, HEIGHT;
    std::map<Coordinate, Field> fields;

  public:
    Board(size_t width = 8, size_t height = 8);

    void populate();
    void move_figure(Move m);
    bool in_bounds(Coordinate c);
    void print() const;
};