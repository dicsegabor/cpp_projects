#include "graph.hpp"

#include <algorithm>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

std::vector<ConnectionType> get_connections(char c)
{
    ConnectionType connection_types[4] = {
        {1,  0 },
        {0,  1 },
        {-1, 0 },
        {0,  -1},
    };

    unsigned int connection_type = c > 57 ? c - 55 : c - 48;

    std::vector<ConnectionType> connections;

    for (int i = 0; i < 4; i++)
    {
        if (connection_type & 0b01) connections.push_back(connection_types[i]);
        connection_type = connection_type >> 1;
    }
    return connections;
}

std::vector<Node>
Graph::neighbours(Node n, std::vector<ConnectionType> connections)
{
    std::vector<Node> neighbours;
    Node temp_node;

    for (const auto &c : connections)
    {
        temp_node = {n.first + c.first, n.second + c.second};
        if (!out_of_bounds(temp_node)) neighbours.push_back(temp_node);
    }

    return neighbours;
}

bool Graph::out_of_bounds(Node n) const
{
    return n.first < 0 || n.first >= dimensions.first || n.second < 0 ||
           n.second >= dimensions.second;
}

Graph::Graph(
    int h, int w, std::vector<Node> obstacles, std::map<Node, char> endpoints
)
    : dimensions({h, w})
{
    // Creating all nodes
    std::vector<Node> nodes;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) nodes.push_back({i, j});

    // Removing obstacle nodes
    std::vector<Node> without_obstacles;
    std::set_difference(
        nodes.begin(), nodes.end(), obstacles.begin(), obstacles.end(),
        std::inserter(without_obstacles, without_obstacles.begin())
    );

    for (auto &n : without_obstacles)
    {
        try
        {
            char c     = endpoints.at(n);
            auto edges = neighbours(n, get_connections(c));
            graph.insert({n, neighbours(n, get_connections(c))});
        }
        catch (const std::out_of_range &oor)
        {
            graph.insert({n, neighbours(n, get_connections('F'))});
        }
    }
}

// static Graph Graph::parse_from_string_array(std::string *input) {}