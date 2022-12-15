#include <iostream>
#include <string>
#include <vector>

#include "graph.hpp"

int main()
{
    int h, w;
    std::cin >> h;
    std::cin >> w;

    Graph g = Graph(h, w);

    // cin leaves a newline character, so we ignore it
    std::cin.ignore();

    // Read all 'h' lines
    std::string lines[h];
    for (int i = 0; i < h; i++) getline(std::cin, lines[i]);

    g.parse_string_array(lines);

    g.print();
}