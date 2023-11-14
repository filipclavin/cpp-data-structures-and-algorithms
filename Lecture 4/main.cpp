#include <stdlib.h>
#include <iostream>

#include "BinarySearchTree.h"

int main() {
	BinarySearchTree* bst = new BinarySearchTree();

	int size;
	std::cout << "Enter the desired tree size: ";
	std::cin >> size;

	for (int i = 0; i < size; i++) {
		bst->InsertNode(rand() % 100 + 1);
	}

	while (true) {
		std::cout << "In-order: " << std::endl;
		bst->PrintInOrder();
		std::cout << std::endl;

		std::cout << "Pre-order: " << std::endl;
		bst->PrintPreOrder();
		std::cout << std::endl;

		std::cout << "Breadth-first: " << std::endl;
		bst->PrintBreadthFirst();
		std::cout << std::endl;

		std::cout << "Tree: " << std::endl;
		bst->PrintTree();

		int deleteVal;
		std::cout << "Enter a value to delete: ";
		std::cin >> deleteVal;

		bst->DeleteNode(deleteVal);
	}

	return 0;
}