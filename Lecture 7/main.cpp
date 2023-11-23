#include <iostream>
#include <chrono>

#include "quickSort.h"
#include "countingSort.h"

int main() {
	std::vector<int> vec = {};

	int n;
	std::cout << "Enter the number of elements: ";
	std::cin >> n;

	int min;
	std::cout << "Enter the minimum value: ";
	std::cin >> min;

	int max;
	std::cout << "Enter the maximum value: ";
	std::cin >> max;

	char log;
	std::cout << "Do you want to see the vector before and after sorting? (y/n): ";
	std::cin >> log;

	for (int i = 0; i < n; i++) {
		int num = rand() % (max - min + 1) + min;
		vec.push_back(num);
	}

	int size = vec.size();

	if (log == 'y') {
		std::cout << "Before sorting: " << std::endl;
		for (int i = 0; i < size; i++) {
			std::cout << vec[i] << " ";
		}
		std::cout << std::endl << std::endl;
	}

	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	//quickSort(vec);
	countingSort(vec);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	std::cout << std::endl << "Time taken: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds" << std::endl << std::endl;

	if (log == 'y') {
		std::cout << "After sorting: " << std::endl;
		for (int i = 0; i < size; i++) {
			std::cout << vec[i] << " ";
		}
	}

	return 0;
}