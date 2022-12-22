#include "graphics.hpp"

int main()
{
    Field f;
    Figure fig = Figure(Type::Pawn, Color::Black);
    f.set_figure(fig);
    Field g = Field(f);

    Board b = Board();
    b.load("default_board.txt");
    print_board(b);
    b.move_figure({{0,1}, {0,2}});
    print_board(b);
    return 0;
}