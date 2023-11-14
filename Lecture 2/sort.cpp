#include "sort.h"

void selectionSort(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		int indexOfMin = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[indexOfMin]) {
				indexOfMin = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[indexOfMin];
		arr[indexOfMin] = temp;
	}
}

void bubbleSort(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		bool swapped = false;
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
				swapped = true;
			}
		}
		if (!swapped) {
			break;
		}
	}
}

void insertionSort(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		int j = i;
		while (j > 0 && arr[j] < arr[j - 1]) {
			int temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
	}
}
