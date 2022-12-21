#pragma once

#include <map>

#include "field.hpp"

class Board
{
    // Variables
  public:
    const size_t WIDTH, HEIGHT;

  private:
    std::map<Coordinate, Field> fields;

    // Methods
  private:
    bool in_bounds(Coordinate c);

  public:
    Board(size_t width = 8, size_t height = 8);

    const std::map<Coordinate, Field> get_fields() const { return fields; }
    
    // TODO: populate from something, probably file
    void populate();
    void move_figure(Move m);
};
