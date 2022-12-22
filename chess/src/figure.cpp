#include "figure.hpp"
#include "rules.hpp"
#include <stdexcept>

Figure::Figure(std::string params)
{
    if (params.length() != 2)
        throw std::invalid_argument("The given string is not valid!");

    type  = type_chars.at(params[0]);
    color = color_chars.at(params[1]);
    moved = false;
}
