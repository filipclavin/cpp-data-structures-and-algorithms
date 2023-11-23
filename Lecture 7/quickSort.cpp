#include "quickSort.h"

void quickSort(std::vector<int>& vec) {
	quickSort(vec, 0, vec.size() - 1);
}

void quickSort(std::vector<int>& vec, int leftIndex, int rightIndex) {
	if (leftIndex >= rightIndex) return;

	int pivotIndex = partition(vec, leftIndex, rightIndex);
	quickSort(vec, leftIndex, pivotIndex - 1);
	quickSort(vec, pivotIndex + 1, rightIndex);
}

int partition(std::vector<int>& vec, int leftIndex, int rightIndex) {
	int pivotValue = vec[rightIndex];

	int i = leftIndex;

	for (int j = leftIndex; j < rightIndex; j++) {
		if (vec[j] <= pivotValue) {
			if (j > i) swap(&vec[i], &vec[j]);
			i++;
		}
	}

	swap(&vec[i], &vec[rightIndex]);

	return i;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
