#pragma once

#include <vector>

#include "vec2.h"

class Node {
public:
	Vec2 position;
	std::vector<Node*> neighbors;
	int id;

	Node(Vec2 position, int id) {
		this->position = position;
		this->id = id;
	}

	float Heuristic(Node* goal) {
		return GetDistance(goal);
	}

	float GetDistance(Node* nodeB) {
		float xDist = position.x - nodeB->position.x;
		float yDist = position.y - nodeB->position.y;
		return sqrt(xDist * xDist + yDist * yDist);
	}
};