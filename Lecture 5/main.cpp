#include <string>
#include <fstream>
#include <vector>

#include "Graph.h"

int main() {
	Graph* graph = new Graph();

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

	graph->PrintDepthFirst(graph->nodes[0]);
	std::cout << "Amount of nodes: " << graph->nodes.size() << std::endl;

	return 0;
}