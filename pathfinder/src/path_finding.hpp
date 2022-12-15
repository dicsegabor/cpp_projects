#pragma once

#include "utilities.hpp"
#include <map>
#include <unordered_map>
#include <vector>

std::map<Node, Node>
breadth_first_search(std::map<Node, std::vector<Node>>, Node start, Node goal);