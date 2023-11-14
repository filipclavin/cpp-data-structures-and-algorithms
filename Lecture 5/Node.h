#pragma once

#include <vector>

#include "Vec2.h"

class Node {
public:
	Vec2 position;
	std::vector<Node*> neighbors;
	int id;

	Node(Vec2 position, int id) {
		this->position = position;
		this->id = id;
	}
};