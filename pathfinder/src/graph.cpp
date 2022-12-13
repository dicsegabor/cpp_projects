#include "graph.hpp"

#include <algorithm>
#include <iterator>
#include <set>
#include <utility>

Graph::Graph(int h, int w, std::set<Node> obstacles, std::set<std::pair<Node, char>> endpoints)
{
    std::set<Node> nodes;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) nodes.insert({i, j});

    std::set<Node> diff;
    std::set_difference(
        nodes.begin(), nodes.end(), obstacles.begin(), obstacles.end(),
        std::inserter(diff, diff.begin())
    );


}

// static Graph Graph::parse_graph(std::string *input) {}