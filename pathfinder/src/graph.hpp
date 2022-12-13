#pragma once

#include <map>
#include <string>
#include <utility>
#include <vector>

typedef std::pair<int, int> Node, Dimensions, ConnectionType;

class Graph
{
    const Dimensions dimensions;
    std::map<Node, std::vector<Node>> graph;

    std::vector<Node> neighbours(Node n, std::vector<std::pair<int, int>> connections);

    bool out_of_bounds(Node n) const;

  public:
    Graph(
        int h, int w, std::vector<Node> obstacles,
        std::map<Node, char> endpoints
    );

    static Graph parse_from_string_array(std::string *input);

    std::map<Node, std::vector<Node>> get_graph() const { return graph; }
};