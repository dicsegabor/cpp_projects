#include "field.hpp"
#include "figure.hpp"

#include <stdexcept>

void Field::move_figure(Field &other)
{
    other.figure = figure;
    figure       = nullptr;
}

void Field::set_figure(const std::shared_ptr<Figure> &f)
{
    if (figure) throw std::invalid_argument("A non empty field cannot be set!");
    if (!f)
        throw std::invalid_argument("A null value cannot be set externally!");
    figure = f;
}

void Field::attack_or_protect_field(const Figure &other)
{
    value_modifier += other.get_type() == figure->get_type() ? 1 : -1;
}
