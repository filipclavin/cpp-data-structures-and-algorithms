#pragma once

#include <vector>

#include "node.h"
#include "map.h"

std::vector<Node*> aStar(Node* start, Node* goal);

std::vector<Node*> reconstructPath(Node* start, Node* end, Map<Node*, Node*> cameFrom);