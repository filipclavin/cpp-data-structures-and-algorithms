#pragma once

#include <string>

enum class Side {
	LEFT,
	RIGHT,
	NONE
};

class Node {
public:
	int value;
	Node* left;
	Node* right;
	Node* parent;
	Side side;

	Node(int value) {
		this->value = value;
		this->left = nullptr;
		this->right = nullptr;
		this->parent = nullptr;
		this->side = Side::NONE;
	}
};

class BinarySearchTree {
public:
	Node* root;

	BinarySearchTree() {
		root = nullptr;
	}

	void InsertNode(int value);

	Node* FindNode(int value);

	void DeleteNode(int value);

	int GetHeight();

	void PrintInOrder();

	void PrintPreOrder();

	void PrintBreadthFirst();

	void PrintTree();

private:
	Node* InsertInSubTree(Node* curr, Node* newNode);

	Node* FindInSubTree(Node* curr, int value);

	Node* DeleteInSubTree(Node* root, int value);

	int GetSubTreeHeight(Node* node);

	Node* PrintSubTreeInOrder(Node* node);

	Node* PrintSubTreePreOrder(Node* node);

	void PrintCurrentLevel(Node* node, int level);

	void PrintSubTree(Node* node, std::string prefix);
};