#include "aStar.h"
#include "map.h"

std::vector<Node*> aStar(Node* start, Node* goal) {
	std::vector<Node*> openSet;
	Map<Node*, Node*>* cameFrom = new Map<Node*, Node*>();
	Map<Node*, float>* gScore = new Map<Node*, float>();
	Map<Node*, float>* fScore = new Map<Node*, float>();

	openSet.push_back(start);
	gScore->Insert(start, 0);
	fScore->Insert(start, start->Heuristic(goal));

	while (openSet.size() > 0) {
		Node* current = openSet[0];

		for (Node* node : openSet) {
			if (fScore->Lookup(node) < fScore->Lookup(current)) {
				current = node;
			}
		}

		if (current == goal) {
			return reconstructPath(start, goal, *cameFrom);
		}

		// remove current from openSet
		openSet.erase(std::remove(openSet.begin(), openSet.end(), current), openSet.end());

		for (Node* neighbor : current->neighbors) {

			float tentativeGScore = gScore->Lookup(current) + current->GetDistance(neighbor);

			float neighborGScore = gScore->Lookup(neighbor);
			if (tentativeGScore < neighborGScore || neighborGScore == 0) {
				cameFrom->Put(neighbor, current);
				gScore->Put(neighbor, tentativeGScore);
				fScore->Put(neighbor, neighborGScore + neighbor->Heuristic(goal));

				//std::vector<Node*> currentPath = reconstructPath(start, neighbor, *cameFrom);

				//std::cout << "Current Path: " << std::endl;
				//for (Node* node : currentPath) {
				//	std::cout << "Node: " << node->id << " ";
				//	node->position.Print();
				//}
				//std::cout << std::endl << std::endl;

				// add neighbor to openSet if not already in it
				if (std::find(openSet.begin(), openSet.end(), neighbor) == openSet.end()) {
					openSet.push_back(neighbor);
				}
			}
		}
	}

	return std::vector<Node*>();

}

std::vector<Node*> reconstructPath(Node* start, Node* end, Map<Node*, Node*>& cameFrom) {
	std::vector<Node*> path;
	Node* current = end;

	while (current != start) {
		path.insert(path.begin(), current);
		current = cameFrom.Lookup(current);
	}

	path.insert(path.begin(), start);

	return path;
}
