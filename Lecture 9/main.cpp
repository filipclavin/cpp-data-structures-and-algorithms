#include <iostream>
#include <chrono>

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

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	mergeSort(vec);
	//quickSort(vec);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	std::cout << "Sorted: " << std::endl;
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds" << std::endl;

	return 0;
}