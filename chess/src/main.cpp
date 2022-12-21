#include "graphics.hpp"

int main()
{
    Board b = Board();
    b.populate();
    print_board(b);
    return 0;
}