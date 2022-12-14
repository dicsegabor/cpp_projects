#include <iostream>
#include <istream>
#include <regex>
#include <string>

#include "graph.hpp"

int main()
{
    int h, w;
    std::cin >> h;
    std::cin >> w;

    Graph g = Graph(h, w);

    std::string line;
    std::cin.ignore();
    // cin leaves a newline character, so we ignore it
    for (int i = 0; i < h; i++)
    {
        getline(std::cin, line);

        auto regex = std::regex("[1234567789abcdefABCDEF]");
        for (std::sregex_iterator ri =
                 std::sregex_iterator(line.begin(), line.end(), regex);
             ri != std::sregex_iterator(); ri++)
        {
            std::smatch sm = *ri;
            g.add_endpoints({
                {{sm.position(), i}, sm.str()[0]}
            });
        }

        regex = std::regex("[xX]");
        for (std::sregex_iterator ri =
                 std::sregex_iterator(line.begin(), line.end(), regex);
             ri != std::sregex_iterator(); ri++)
        {
            std::smatch sm = *ri;
            g.add_obstacles({
                {sm.position(), i}
            });
        }
    }

    g.print();
}