#pragma once

#include <list>

#include "Node.h"

class Graph {
public:
	std::vector<Node*> nodes;

	void PrintDepthFirst(Node* startNode);
};