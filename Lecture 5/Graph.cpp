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

void Graph::AddNeighbors() {
	for (Node* node : nodes) {
		for (Node* otherNode : nodes) {
			if (
				otherNode->position.x == node->position.x - 1 && otherNode->position.y == node->position.y ||
				otherNode->position.x == node->position.x + 1 && otherNode->position.y == node->position.y ||
				otherNode->position.x == node->position.x && otherNode->position.y == node->position.y - 1 ||
				otherNode->position.x == node->position.x && otherNode->position.y == node->position.y + 1
				) {
				node->neighbors.push_back(otherNode);
			}
		}
	}
}