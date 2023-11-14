#include <stdlib.h>
#include <iostream>

#include "sort.h"
#include "search.h"

int main() {

	int randomArr[100]{};

	for (int i = 0; i < 100; i++) {
		randomArr[i] = rand() % 100 + 1;
	}

	std::cout << "Before Sort" << std::endl;
	for (int i = 0; i < 100; i++) {
		std::cout << randomArr[i] << std::endl;
	}

	//selectionSort(randomArr, 100);
	//bubbleSort(randomArr, 100);
	insertionSort(randomArr, 100);

	std::cout << std::endl << "After Sort" << std::endl;
	for (int i = 0; i < 100; i++) {
		std::cout << randomArr[i] << std::endl;
	}

	int searchVal;
	std::cout << std::endl << "Enter a number to search for: " << std::endl;
	std::cin >> searchVal;

	std::cout << std::endl << "Searching for " << searchVal << "..." << std::endl;
	int index = binarySearch(randomArr, searchVal, 0, 99);
	std::cout << "Index of " << searchVal << ": " << index << std::endl;

	return 0;
}