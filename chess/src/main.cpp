#include "graphics.hpp"

int main()
{
    Board b = Board();
    b.load("default_board.txt");
    print_board(b);
    return 0;
}