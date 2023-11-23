#pragma once

#include <vector>

void quickSort(std::vector<int>& vec);

void quickSort(std::vector<int>& vec, int leftIndex, int rightIndex);

int partition(std::vector<int>& vec, int leftIndex, int rightIndex);

void swap(int* a, int*b);