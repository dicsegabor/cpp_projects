#include "graph.hpp"
#include "utilities.hpp"

#include <algorithm>
#include <map>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <iostream>

// Creates the edges to all possible neighbours
std::vector<Node>
Graph::get_neighbours(Node n, std::vector<ConnectionType> connections)
{
    std::vector<Node> neighbours;
    for (const auto &c : connections)
    {
        Node temp_node = {n.first + c.first, n.second + c.second};
        if (!out_of_bounds(temp_node)) neighbours.push_back(temp_node);
    }

    return neighbours;
}

// Tests if the give n node is outside of the dimensions of the graph
bool Graph::out_of_bounds(Node n) const
{
    return n.first < 0 || n.first >= dimensions.first || n.second < 0 ||
           n.second >= dimensions.second;
}

void Graph::disconnect_node(Node n, std::vector<ConnectionType> connections)
{
    std::vector<Node> &edges = graph.at(n);
    for (auto &neighbour : get_neighbours(n, connections))
    {
        try
        {
            std::vector<Node> &n_edges = graph.at(neighbour);
            n_edges.erase(std::find(n_edges.begin(), n_edges.end(), n));
        }
        catch (const std::out_of_range &oor)
        {
        }

        edges.erase(std::find(edges.begin(), edges.end(), neighbour));
    }
}

Graph::Graph(int h, int w) : dimensions({h, w})
{
    // Creating all nodes based on the give dimensions
    std::vector<Node> nodes;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) nodes.push_back({j, i});

    // Creating all edges
    for (auto &n : nodes)
        graph.insert({n, get_neighbours(n, get_connections('F'))});
}

void Graph::add_endpoints(std::map<Node, char> endpoints)
{
    for (const auto &ep : endpoints)
        disconnect_node(ep.first, get_connections(ep.second, true));
}

void Graph::add_obstacles(std::vector<Node> obstacles)
{
    for (const auto &o : obstacles)
    {
        disconnect_node(o, get_connections('F'));
        graph.erase(o);
    }
}

void Graph::print() const
{
    for (const auto &n : graph)
    {
        std::cout << "(" << n.first.first << ", " << n.first.second
                  << ") -> [ ";
        for (const auto &e : n.second)
            std::cout << "(" << e.first << ", " << e.second << ") ";

        std::cout << "]\n";
    }
}