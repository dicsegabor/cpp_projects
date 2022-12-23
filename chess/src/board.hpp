#pragma once

#include <map>

#include "other.hpp"
#include "field.hpp"

// TODO: Creating a separate IO class

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
    // Constructors
    Board(size_t width = 8, size_t height = 8);

    // Getters, setters
    const std::map<Coordinate, Field> get_fields() const { return fields; }

    // IO
    void load(std::string file);

    // Other
    bool move_figure(Move m);
};
