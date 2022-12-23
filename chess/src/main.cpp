#include "graphics.hpp"

int main()
{
    Board b = Board();
    b.load("default_board.txt");
    print_board(b);
    b.move_figure({{0,1}, {0,2}});
    print_board(b);
    b.move_figure({{3,7}, {1,5}});
    print_board(b);
    return 0;
}