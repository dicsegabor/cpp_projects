#pragma once

#include "figure.hpp"

class Field
{

  public:
    Figure *figure;
    void move_figure(Field &other);
    const Figure* get_figure() const { return figure; }
};