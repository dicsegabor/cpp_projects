#include "field.hpp"
#include "figure.hpp"

#include <algorithm>
#include <memory>
#include <stdexcept>
#include <utility>

void Field::move_figure(Field &other)
{
    other.figure = std::move(figure);
}

void Field::set_figure(Figure f)
{
    if (figure) throw std::invalid_argument("A non empty field cannot be set!");
    figure = std::unique_ptr<Figure>(new Figure(f));
}

void Field::attack_or_protect_field(const Figure &other)
{
    value_modifier += other.get_type() == figure->get_type() ? 1 : -1;
}
