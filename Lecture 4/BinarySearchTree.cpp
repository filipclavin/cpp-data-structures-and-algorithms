#include <iostream>

#include "BinarySearchTree.h"

void BinarySearchTree::InsertNode(int value) {
	Node* newNode = new Node(value);

	if (root == nullptr) {
		root = newNode;
	} else {
		InsertInSubTree(root, newNode);
	}
}

Node* BinarySearchTree::InsertInSubTree(Node* curr, Node* newNode) {
	if (newNode->value <= curr->value) {
		if (curr->left == nullptr) {
			curr->left = newNode;
			curr->left->parent = curr;
			curr->left->side = Side::LEFT;

		} else {
			InsertInSubTree(curr->left, newNode);
		}

	} else if (newNode->value > curr->value) {
		if (curr->right == nullptr) {
			curr->right = newNode;
			curr->right->parent = curr;
			curr->right->side = Side::RIGHT;

		} else {
			InsertInSubTree(curr->right, newNode);
		}

	}

	return curr;

	// this function doesn't order the tree correctly )
}

Node* BinarySearchTree::FindNode(int value) {
	if (root != nullptr) {
		return FindInSubTree(root, value);
	} else {
		return nullptr;
	}
}

Node* BinarySearchTree::FindInSubTree(Node* curr, int value) {
	if (curr->value == value) {
		return curr;

	} else if (value < curr->value) {
		if (curr->left != nullptr) {
			return FindInSubTree(curr->left, value);
		}

	} else if (value > curr->value) {
		if (curr->right != nullptr) {
			return FindInSubTree(curr->right, value);
		}
	}

	return nullptr;
}

void BinarySearchTree::DeleteNode(int value) {
	if (root != nullptr) {
		root = DeleteInSubTree(root, value);
	}
}


Node* BinarySearchTree::DeleteInSubTree(Node* curr, int value) {
	// Traversal start
	if (curr == nullptr) { // This child doesn't exist
		return curr;

	} else if (value < curr->value) { // Node is in left subtree
		curr->left = DeleteInSubTree(curr->left, value);

	} else if (value > curr->value) { // Node is in right subtree
		curr->right = DeleteInSubTree(curr->right, value);

	} else { // Traversal end
		// Deletion logic
		if (curr->left == nullptr && curr->right == nullptr) { // Leaf node
			delete curr;
			curr = nullptr;

		} else if (curr->left == nullptr) { // Node with only right child
			Node* temp = curr;
			curr = curr->right;
			delete temp;

		} else if (curr->right == nullptr) { // Node with only left child
			Node* temp = curr;
			curr = curr->left;
			delete temp;

		} else { // Node with two children
			// Find the smallest value in the right subtree
			Node* temp = curr->right;
			while (temp->left != nullptr) {
				temp = temp->left;
			}

			// Replace the current node with the smallest value
			curr->value = temp->value;
			curr->right = DeleteInSubTree(curr->right, temp->value);
		}
	}

	return curr;
}

void BinarySearchTree::PrintTree() {
	if (root != nullptr) {
		PrintSubTree(root, "");
	}
}

void BinarySearchTree::PrintSubTree(Node* node, std::string prefix) {

	std::cout << prefix + (node == root ? "" :
		node->side == Side::LEFT ? "L---" : "R---") << node->value << std::endl;

	if (node->left != nullptr) {
		PrintSubTree(node->left, prefix + (node->side == Side::LEFT && node->parent->right != nullptr ? "|   " : "    "));
	}

	if (node->right != nullptr) {
		PrintSubTree(node->right, prefix + (node->side == Side::LEFT && node->parent->right != nullptr ? "|   " : "    "));
	}
}

void BinarySearchTree::PrintInOrder() {
	if (root != nullptr) {
		PrintSubTreeInOrder(root);
	}
}

Node* BinarySearchTree::PrintSubTreeInOrder(Node* curr) {
	if (curr->left != nullptr) {
		PrintSubTreeInOrder(curr->left);
	}

	std::cout << curr->value << std::endl;

	if (curr->right != nullptr) {
		PrintSubTreeInOrder(curr->right);
	}

	return curr;
}

void BinarySearchTree::PrintPreOrder() {
	if (root != nullptr) {
		PrintSubTreePreOrder(root);
	}
}

Node* BinarySearchTree::PrintSubTreePreOrder(Node* curr) {
	std::cout << curr->value << std::endl;

	if (curr->left != nullptr) {
		PrintSubTreePreOrder(curr->left);
	}

	if (curr->right != nullptr) {
		PrintSubTreePreOrder(curr->right);
	}

	return curr;
}

int BinarySearchTree::GetHeight() {
	if (root != nullptr) {
		return GetSubTreeHeight(root);
	} else {
		return 0;
	}
}

int BinarySearchTree::GetSubTreeHeight(Node* curr) {
	if (curr == nullptr) {
		return 0;
	}

	else {
		int leftHeight = GetSubTreeHeight(curr->left);
		int rightHeight = GetSubTreeHeight(curr->right);

		if (leftHeight > rightHeight) {
			return (leftHeight + 1);

		} else {
			return (rightHeight + 1);
		}
	}
}

void BinarySearchTree::PrintBreadthFirst() {
	int height = GetHeight();

	if (root != nullptr) {
		for (int i = 0; i < height; i++) {
			PrintCurrentLevel(root, i);
			std::cout << std::endl;
		}
	}
}


void BinarySearchTree::PrintCurrentLevel(Node* node, int level) {
	if (node == nullptr) {
		return;
	}

	if (level == 0) { // We are at the correct level
		std::cout << node->value << " ";

	} else if (level > 0) { // We are not at the correct level, dig into children
		PrintCurrentLevel(node->left, level - 1);
		PrintCurrentLevel(node->right, level - 1);
	}
}