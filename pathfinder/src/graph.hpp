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

    bool out_of_bounds(Node n) const;

    void disconnect_node(Node n, std::vector<ConnectionType> connections);

    std::vector<Node>
    get_neighbours(Node n, std::vector<ConnectionType> connections);

  public:
    Graph(int h, int w);

    void add_endpoints(std::map<Node, char> endpoints);

    void add_obstacles(std::vector<Node> obstacles);

    static Graph parse_from_string_array(std::string *input);

    void print() const;
};