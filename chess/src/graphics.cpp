#include "graphics.hpp"

#include <iostream>
#include <sstream>

// Dont put \n on the end of the text
std::string color_text(std::string text, Color foreground, Color background)
{
    std::stringstream ss;
    ss << "\033[" << foreground << ";" << (background + 10) << "m" << text
       << "\033[0m";
    return ss.str();
}

std::string figure_to_string(const Figure &f)
{
    switch (f.get_type())
    {
        case Type::Pawn : return "P";
        case Type::Bishop : return "B";
        case Type::Knight : return "N";
        case Type::Rook : return "R";
        case Type::Queen : return "Q";
        case Type::King : return "K";
        default : return " ";
    }
}

void print_board(const Board b)
{

    Color dark = Color::Yellow, light = Color::Green;
    Color background = dark;
    for (size_t y = 0; y < b.HEIGHT; y++)
    {
        for (size_t x = 0; x < b.WIDTH; x++)
        {
            auto f = b.get_fields().at({x, y}).get_figure();
            if (f)
                std::cout << color_text(
                    figure_to_string(*f), f->get_color(), background
                );
            else
                std::cout << color_text(" ", light, background);

            background = background == dark ? light : dark;
        }
        std::cout << "\n";
        background = background == dark ? light : dark;
    }
}