#include <iostream>

#include "sort.h"

int main() {
	int n;
	std::cout << "Enter the number of elements: ";
	std::cin >> n;

	int r;
	std::cout << "Enter the range of elements: ";
	std::cin >> r;

	std::vector<int> vec;

	for (int i = 0; i < n; i++) {
		vec.push_back(rand() % r);
	}

	std::cout << "Unsorted: " << std::endl;
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	mergeSort(vec);

	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}

	return 0;
}