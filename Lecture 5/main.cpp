#include <string>
#include <fstream>
#include <vector>

#include "Graph.h"

void addNeighbors(Graph* graph) {
	for (Node* node : graph->nodes) {
		for (Node* otherNode : graph->nodes) {
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



int main() {
	Graph* graph = new Graph();

	/*
	Node* node1 = new Node(Vec2(0, 0), 1);
	Node* node2 = new Node(Vec2(1, 0), 2);
	Node* node3 = new Node(Vec2(0, 1), 3);
	Node* node4 = new Node(Vec2(1, 1), 4);
	Node* node5 = new Node(Vec2(2, 1), 5);
	Node* node6 = new Node(Vec2(1, 2), 6);
	Node* node7 = new Node(Vec2(2, 2), 7);
	Node* node8 = new Node(Vec2(3, 1), 8);
	Node* node9 = new Node(Vec2(1, 3), 9);
	Node* node10 = new Node(Vec2(3, 3), 10);

	node1->neighbors.push_back(node2);
	node1->neighbors.push_back(node3);
	node2->neighbors.push_back(node4);
	node3->neighbors.push_back(node4);
	node4->neighbors.push_back(node5);
	node4->neighbors.push_back(node6);
	node5->neighbors.push_back(node7);
	node6->neighbors.push_back(node7);
	node7->neighbors.push_back(node8);
	node7->neighbors.push_back(node9);
	node8->neighbors.push_back(node10);
	node9->neighbors.push_back(node10);

	graph->nodes.push_back(node1);
	graph->nodes.push_back(node2);
	graph->nodes.push_back(node3);
	graph->nodes.push_back(node4);
	graph->nodes.push_back(node5);
	graph->nodes.push_back(node6);
	graph->nodes.push_back(node7);
	graph->nodes.push_back(node8);
	graph->nodes.push_back(node9);
	graph->nodes.push_back(node10);

	graph->PrintDepthFirst(node1);
	*/

	std::string filePath;
	std::cout << "Enter file path: ";
	std::cin >> filePath;

	std::ifstream file(filePath);

	std::vector<std::string> lines;

	if (!file.is_open()) {
		std::cout << "Could not open file";
		return -1;
	}

	std::string line;

	while (std::getline(file, line)) {
		lines.push_back(line);
	}

	file.close();

	for (int y = 0; y < lines.size(); y++) {
		std::string line = lines[y];

		for (int x = 0; x < line.size(); x++) {
			char c = line[x];
			if (c == 'X') continue;

			Node* node = new Node(Vec2(x, y), graph->nodes.size() + 1);
			graph->nodes.push_back(node);
		}
	}

	addNeighbors(graph);

	graph->PrintDepthFirst(graph->nodes[0]);
	std::cout << "Amount of nodes: " << graph->nodes.size() << std::endl;

	return 0;
}