#include "Graph.h"

bool Contains(std::vector<Node*>& nodeVec, Node* node) {
	for (Node* n : nodeVec) {
		if (n == node) {
			return true;
		}
	}

	return false;
}

void DepthFirstHelper(Node* currentNode, std::vector<Node*>& visitedNodes) {
	visitedNodes.push_back(currentNode);
	currentNode->position.Print();
	for (Node* neighbor : currentNode->neighbors) {
		if (Contains(visitedNodes, neighbor)) continue;
		DepthFirstHelper(neighbor, visitedNodes);
	}
}

void Graph::PrintDepthFirst(Node* startNode) {
	std::vector<Node*> visited {};

	DepthFirstHelper(startNode, visited);
}
