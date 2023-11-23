#include <fstream>
#include <string>

#include "graph.h"
#include "aStar.h"

Graph* createGraph();

int main() {
	Graph* graph = createGraph();

	char randomize;
	std::cout << "Randomize positions? (y/n): ";
    std::cin >> randomize;
	
	if (randomize == 'y') {
		for (Node* node : graph->nodes) {
			node->position = Vec2(1 + rand() % 100, 1 + rand() % 100);
		}
	}

	std::vector<Node*> path = aStar(graph->nodes[0], graph->nodes[graph->nodes.size() - 1]);

	if (path.size() == 0) {
		std::cout << "No path found" << std::endl;
		return 0;
	}

	std::cout << "Path: " << std::endl;
	for (Node* node : path) {
		std::cout << "Node: " << node->id << " ";
		node->position.Print();
	}

	return 0;
}

Graph* createGraph() {
	Graph* graph = new Graph();

	std::ifstream file("Files/GraphNodes.txt");

	std::vector<std::string> lines;

	if (!file.is_open()) {
		std::cout << "Could not open file";
		return nullptr;
	}

	std::string line;

	while (std::getline(file, line) && (line[0] == 'o' || line[0] == 'X')) {
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

	graph->AddNeighbors();

	//graph->PrintDepthFirst(graph->nodes[0]);
	//std::cout << "Amount of nodes: " << graph->nodes.size() << std::endl;

	return graph;
}