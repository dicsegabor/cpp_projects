#pragma once

#include "figure.hpp"
#include <memory>

class Field
{
    // Variables
  private:
    // For managing attacks and protections on the field
    int value_modifier;
    std::shared_ptr<Figure> figure;

    // Methods
  public:
    Field() : value_modifier(0), figure(nullptr) {}
    Field(std::shared_ptr<Figure> figure) : value_modifier(0), figure(figure) {}

    // Getters, setters
    int get_value() const { return value_modifier + figure->get_value(); }
    std::shared_ptr<Figure> const get_figure() const { return figure; }
    void set_figure(const std::shared_ptr<Figure> &f);

    void move_figure(Field &other);
    void attack_or_protect_field(const Figure &other);
};