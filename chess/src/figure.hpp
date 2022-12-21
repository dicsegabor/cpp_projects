#pragma once

#include "rules.hpp"

class Figure
{
    // Variables
  public:
  private:
    Type type;
    Color color;
    bool moved;

    // Methods
  public:
    Figure(Type type, Color color) : type(type), color(color), moved(false) {}

    // Getters, setters
    Type get_type() const { return type; }
    Color get_color() const { return color; }
    bool get_moved() const { return moved; }
    int get_value() { return figure_values.at(type); };

    void set_type(Type type) { this->type = type; }
    void set_moved() { moved = true; }
};