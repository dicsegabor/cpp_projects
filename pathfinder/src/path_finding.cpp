#include "path_finding.hpp"

#include <queue>

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