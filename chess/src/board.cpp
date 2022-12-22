#include "board.hpp"
#include "figure.hpp"
#include "rules.hpp"

#include <cstddef>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>

Board::Board(size_t width, size_t height) : WIDTH(width), HEIGHT(height)
{
    for (size_t y = 0; y < HEIGHT; y++)
        for (size_t x = 0; x < WIDTH; x++)
            fields.insert({
                {x, y},
                Field()
            });
}

bool Board::in_bounds(Coordinate c)
{
    return c.x >= 0 && c.x < WIDTH && c.y >= 0 && c.y < HEIGHT;
}

void Board::load(std::string file)
{
    std::ifstream infile(file);
    std::string line;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);

        char t, c;
        bool moved;
        size_t x, y;
        if (!(iss >> t >> c >> moved >> x >> y))
        {
            throw std::invalid_argument(
                "Te given line '" + line + "' is incorrect!"
            );
        }

        auto type  = type_chars.at(t);
        auto color = color_chars.at(c);
        fields.at({x, y}).set_figure(
            std::make_shared<Figure>(Figure(type, color, moved))
        );
    }

    infile.close();
}

void Board::move_figure(Move m)
{
    if (!in_bounds(m.first) || !in_bounds(m.second))
        throw std::invalid_argument("The given move is out of bounds!");

    auto from = fields.at(m.first);
    auto to   = fields.at(m.second);

    from.move_figure(to);
}
