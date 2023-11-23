#include "sort.h"

std::vector<int> merge(std::vector<int> left, std::vector<int> right);

void mergeSort(std::vector<int>& vec) {
	int size = vec.size();

	if (size < 2) {
		return;
	}

	std::vector<int> left;
	std::vector<int> right;

	int mid = size / 2;

	for (int i = 0; i < mid; i++) {
		left.push_back(vec[i]);
	}

	for (int i = mid; i < size; i++) {
		right.push_back(vec[i]);
	}

	mergeSort(left);
	mergeSort(right);

	vec = merge(left, right);
}

std::vector<int> merge(std::vector<int> left, std::vector<int> right) {
	std::vector<int> result;

	while (left.size() > 0 && right.size() > 0) {
		if (left[0] < right[0]) {
			result.push_back(left[0]);
			left.erase(left.begin());
		} else {
			result.push_back(right[0]);
			right.erase(right.begin());
		}
	}

	while (left.size() > 0) {
		result.push_back(left[0]);
		left.erase(left.begin());
	}

	while (right.size() > 0) {
		result.push_back(right[0]);
		right.erase(right.begin());
	}

	return result;
}
