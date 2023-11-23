#include "countingSort.h"

void countingSort(std::vector<int> &vec) {
	int size = vec.size();

	int max = *std::max_element(vec.begin(), vec.end());
	std::vector<int> count(max+1, 0);

	for (int i = 0; i < size; i++) {
		count[vec[i]]++; // count number of times each element appears
	}

	for (int i = 1; i < count.size(); i++) {
		count[i] += count[i-1]; // tells us how many elements are less than or equal to each element
	}

	std::vector<int> sorted(size, 0);
	for (int i = size -1; i >= 0; i--) { // iterate through input backwards
										 // (lets us figure out the position of next element of same value by decrementing the count of that value)

		sorted[count[vec[i]] - 1] = vec[i]; // put element in sorted array at the indicated index
											// (-1 because the count of each value that exists in the input vector starts at 1)

		count[vec[i]]--; // decrement count of element to put next element of same value in spot before
	}

	vec = sorted;
}
