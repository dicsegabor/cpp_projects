#include "board.hpp"
#include "figure.hpp"
#include "rules.hpp"

#include <memory>
#include <stdexcept>

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

void Board::populate()
{
    fields.at({0, 7}).set_figure(
        std::make_shared<Figure>(Figure(Type::Pawn, Color::Black))
    );
    fields.at({1, 7}).set_figure(
        std::make_shared<Figure>(Figure(Type::Pawn, Color::White))
    );
}

void Board::move_figure(Move m)
{
    if (!in_bounds(m.first) || !in_bounds(m.second))
        throw std::invalid_argument("The given move is out of bounds!");

    auto from = fields.at(m.first);
    auto to   = fields.at(m.second);

    from.move_figure(to);
}
