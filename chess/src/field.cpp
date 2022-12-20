#include "field.hpp"

    void Field::move_figure(Field &other)
    {
        other.figure = figure;
        figure = nullptr;
    }
