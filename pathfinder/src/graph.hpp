#pragma once

#include <map>
#include <string>
#include <utility>
#include <vector>

typedef std::pair<int, int> Node, Dimensions, ConnectionType;

class Graph
{
    const char sn_charset[3] = "tT";
    const char ep_charset[22] = "123456789abcdefABCDEF";
    const char ob_charset[3] = "xX";

    const std::pair<size_t, size_t> dimensions;
    Node start_node;
    std::vector<Node> endpoints;
    std::map<Node, std::vector<Node>> graph;

    bool out_of_bounds(Node n) const;

    void disconnect_node(Node n, std::vector<ConnectionType> connections);

    std::vector<Node>
    get_neighbours(Node n, std::vector<ConnectionType> connections);

  public:
    Graph(int h, int w);

    void add_endpoints(std::map<Node, char> endpoints);

    void add_obstacles(std::vector<Node> obstacles);

    void clear_unconnected_nodes();

    void parse_string_array(const std::string *input);

    void print() const;
};