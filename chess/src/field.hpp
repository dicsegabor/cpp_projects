#pragma once

#include "figure.hpp"
#include <exception>
#include <memory>
#include <stdexcept>
#include <utility>

class Field
{
    // Variables
  private:
    // For managing attacks and protections on the field
    int value_modifier;
    std::unique_ptr<Figure> figure;

    // Methods
  public:
    Field() : value_modifier(0) {}

    Field(const Field &other)
        : value_modifier(other.value_modifier),
          figure(std::unique_ptr<Figure>(new Figure(*other.figure)))
    {
    }

    // Getters, setters
    int get_value() const { return value_modifier + figure->get_value(); }
    const std::unique_ptr<Figure> &get_figure() const { return figure; }
    void set_figure(const Figure &f);

    void move_figure(Field &other);
    void attack_or_protect_field(const Figure &other);
};