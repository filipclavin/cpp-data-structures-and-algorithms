#pragma once
#include <string>

struct Vec3 {
	float x;
	float y;
	float z;

	std::string toString() {
		return std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z);
	}
};