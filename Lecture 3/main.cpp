#include <stdlib.h>
#include <iostream>
#include <chrono>

#include "sort.h"
#include "search.h"

int main() {
	int iterationCount = 0;
	std::cout << "How many iterations? ";
	std::cin >> iterationCount;

	int indexCount = 0;
	std::cout << "How many indexes? ";
	std::cin >> indexCount;

	long long totalSortTime = 0;
	long long hiSortTime = 0;
	long long loSortTime = 0;

	long long totalSearchTime = 0;
	long long hiSearchTime = 0;
	long long loSearchTime = 0;

	for (int i = 0; i < iterationCount; i++) {
		int *randomArr = new int[indexCount]{};

		for (int j = 0; j < indexCount; j++) {
			randomArr[j] = rand() % 100 + 1;
		}

		std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
		//selectionSort(randomArr, indexCount);
		//bubbleSort(randomArr, indexCount);
		insertionSort(randomArr, indexCount);
		std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

		long long sortRes = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
		totalSortTime += sortRes;

		if (hiSortTime == 0 || sortRes > hiSortTime) {
			hiSortTime = sortRes;
		}

		if (loSortTime == 0 || sortRes < loSortTime) {
			loSortTime = sortRes;
		}

		int searchVal = rand() % 100 + 1;

		begin = std::chrono::steady_clock::now();
		binarySearch(randomArr, searchVal, 0, indexCount - 1);
		end = std::chrono::steady_clock::now();

		long long searchRes = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
		totalSearchTime += searchRes;

		if (hiSearchTime == 0 || searchRes > hiSearchTime) {
			hiSearchTime = searchRes;
		}

		if (loSearchTime == 0 || searchRes < loSearchTime) {
			loSearchTime = searchRes;
		}

		delete[] randomArr;
	}

	std::cout << "\nAverage sort time: " << totalSortTime / iterationCount << " microseconds" << std::endl;
	std::cout << "Highest sort time: " << hiSortTime << " microseconds" << std::endl;
	std::cout << "Lowest sort time: " << loSortTime << " microseconds" << std::endl << std::endl;

	std::cout << "Average search time: " << totalSearchTime / iterationCount << " microseconds" << std::endl;
	std::cout << "Highest search time: " << hiSearchTime << " microseconds" << std::endl;
	std::cout << "Lowest search time: " << loSearchTime << " microseconds" << std::endl;

	return 0;
}