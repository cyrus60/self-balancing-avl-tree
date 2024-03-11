// Contains class AVLTree
#include <iostream>
using namespace std;

#pragma once

class AVLTree {
// defines class for AVLTree nodes that will contain a key, a height, and left/right pointers
private:
	class Node {
	public:
		int key; 
		int height = 0;
		Node* left = nullptr;
		Node* right = nullptr;
		Node(int newKey): key(newKey), left(nullptr), right(nullptr) {}
	};

	// pointer to the root of the AVLTree
	Node* root;

	/// @brief insertHelper, recursive function that traverses tree and inserts key respectively
	/// @param int key key to be inserted 
	/// @param Node*& reference to current node 
	/// @return boolean whether or not key was successfully inserted
	bool insertHelper(int, Node*&);

public:

	AVLTree();

	bool insert(int);
};