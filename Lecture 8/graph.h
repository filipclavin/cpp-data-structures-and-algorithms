#pragma once

#include <list>

#include "node.h"

class Graph {
public:
	std::vector<Node*> nodes;

	void PrintDepthFirst(Node* startNode);

	void AddNeighbors();
};