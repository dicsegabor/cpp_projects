#include "graph.hpp"
#include "utilities.hpp"

#include <algorithm>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

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

void Graph::disconnect_node(Node n, std::vector<Node> i_connections)
{
    std::vector<Node> &edges = graph.at(n);
    for (auto &neighbour : get_neighbours(n, i_connections))
    {
        try
        {
            std::vector<Node> &n_edges = graph.at(neighbour);
            auto it = std::find(n_edges.begin(), n_edges.end(), n);
            if (it != n_edges.end()) n_edges.erase(it);
        }
        catch (const std::out_of_range &oor)
        {
        }

        edges.erase(std::find(edges.begin(), edges.end(), neighbour));
    }
}

Graph::Graph(int h, int w) : dimensions({w, h})
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
    {
        disconnect_node(ep.first, get_connections(ep.second, true));
        this->endpoints.push_back(ep.first);
    }
}

void Graph::add_obstacles(std::vector<Node> obstacles)
{
    for (const auto &o : obstacles)
    {
        disconnect_node(o, get_connections('F'));
        graph.erase(o);
    }
}

void Graph::clear_unconnected_nodes()
{
    for (auto it = endpoints.begin(); it != endpoints.end(); it++)
        if (graph.at(*it).empty()) endpoints.erase(it);

    for (auto &n : graph)
        if (n.second.empty()) graph.erase(n.first);
}

void Graph::parse_string_array(const std::string *input)
{
    std::map<Node, char> endpoints_with_type;
    std::vector<Node> obstacles;

    for (size_t i = 0; i < dimensions.second; i++)
    {
        for (size_t j = 0; j < dimensions.first; j++)
        {
            char c = input[i][j];
            if (contains(ep_charset, c))
            {
                endpoints_with_type.insert({
                    {j, i},
                    c
                });
            }
            else if (contains(ob_charset, c)) { obstacles.push_back({j, i}); }
            else if (contains(sn_charset, c)) { start_node = {j, i}; }
        }
    }

    add_endpoints(endpoints_with_type);
    add_obstacles(obstacles);
    clear_unconnected_nodes();
}

void Graph::print() const
{
    if (graph.empty())
        std::cout << "The graph is empty!\n";
    else
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
}