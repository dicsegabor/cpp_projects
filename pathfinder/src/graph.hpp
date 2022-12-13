#pragma once

#include <map>
#include <string>
#include <utility>
#include <set>

typedef std::pair<int, int> Node;
typedef std::pair<Node, Node> Edge;

class Graph
{
    std::map<Node, std::set<Edge>> graph;

  public:
    Graph(int h, int w, std::set<Node> endpoints, std::set<std::pair<Node, char>> obstacles);

    static Graph parse_graph(std::string *input);

    std::map<Node, std::set<Edge>> get_graph() const { return graph; }
};