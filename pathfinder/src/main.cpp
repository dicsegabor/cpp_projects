#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "graph.hpp"
#include "path_finding.hpp"

bool contains(std::vector<Node> vec, Node n)
{
    return std::find(vec.begin(), vec.end(), n) != vec.end();
}

int main()
{
    int h, w;
    std::cin >> h;
    std::cin >> w;

    Graph g = Graph(h, w);

    // cin leaves a newline character, so we ignore it
    std::cin.ignore();

    // Read all 'h' lines
    std::string lines[h];
    for (int i = 0; i < h; i++) getline(std::cin, lines[i]);

    g.parse_string_array(lines);

    std::vector<Node> solution;

    int sum = 0;
    for (const auto &ep : g.get_endpoints())
    {
        auto came_from =
            breadth_first_search(g.get_graph(), g.get_start_node(), ep);

        int i = -1;
        for (Node start = ep; start != g.get_start_node();
             start      = came_from[start])
        {
            solution.push_back(start);
            i++;
        }

        // Only for displaying
        solution.push_back(g.get_start_node());

        std::cout << "L = " << i << "\n";
        for(const auto &n : solution)
        {
            std::cout << "(" << n.first << ", " << n.second << ")->";
        }
        std::cout << "\n";
        solution.pop_back();
        solution.erase(solution.begin());
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (contains(solution, {j, i}))
                    std::cout << "@";
                else
                    std::cout << lines[i][j];
            }
            std::cout << "\n";
        }

        solution.clear();
        std::cout << "\n";
        //////

        sum += i;
    }

    std::cout << sum << "\n";
}