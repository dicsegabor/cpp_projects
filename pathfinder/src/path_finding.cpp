#include "path_finding.hpp"
#include "utilities.hpp"

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::map<Node, Node> breadth_first_search(
    std::map<Node, std::vector<Node>> graph, Node start, Node goal
)
{
    std::queue<Node> frontier;
    frontier.push(start);

    std::map<Node, Node> came_from = {
        {start, start}
    };

    while (!frontier.empty())
    {
        Node current = frontier.front();
        frontier.pop();

        if (current == goal) { break; }

        for (Node next : graph.at(current))
        {
            if (came_from.find(next) == came_from.end())
            {
                frontier.push(next);
                came_from[next] = current;
            }
        }
    }
    return came_from;
}

int path_length(std::map<Node, Node> paths, Node start, Node goal)
{
    int sum = 0;
    for (Node start = goal; start != start; start = paths[start]) { sum++; }

    // Removing the starting node
    return sum - 1;
}

// reconstructs the path in reverse
std::vector<Node>
reconstruct_path(std::map<Node, Node> paths, Node start, Node goal)
{
    std::vector<Node> path;
    for (Node it = goal; it != start; it = paths[it]) { path.push_back(it); }
    path.push_back(start);
    return path;
}

void print_path(std::vector<Node> path, const std::string *lines)
{
    // displaying length
    std::cout << "L = " << (path.size() - 2) << "\n";

    // displaying path by nodes
    for (const auto &n : path)
    {
        std::cout << "(" << n.first << ", " << n.second << ") ";
    }
    std::cout << "\n";

    // removing first and last element, so we can see them on the map
    path.pop_back();
    path.erase(path.begin());

    // displaying path on original map
    for (size_t i = 0; i < lines->size(); i++)
    {
        for (size_t j = 0; j < lines[i].size(); j++)
        {
            if (contains<Node>(path, {j, i})) { std::cout << "@"; }
            else { std::cout << lines[i][j]; }
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}