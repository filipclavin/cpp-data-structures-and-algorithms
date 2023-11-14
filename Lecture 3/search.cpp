#include <iostream>

#include "search.h"

int binarySearch(int* arr, int val, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (val == arr[mid]) {
            return mid;
        }

        if (val > arr[mid]) {
            low = mid + 1;
        }

        if (val < arr[mid]) {
            high = mid - 1;
        }

    }

    return -1;
}
