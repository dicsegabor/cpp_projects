#include <iostream>

#include "graph.hpp"

int main()
{
    Graph g = Graph(2, 2, {{1,0}}, {{{0,0}, '4'}});

    for(const auto &n : g.get_graph())
    {
        std::cout << "(" << n.first.first << ", " << n.first.second << ") -> [ ";
        for(const auto &e : n.second)
            std::cout << "(" << e.first << ", " << e.second << ") ";

        std::cout << "]\n";
    }
}