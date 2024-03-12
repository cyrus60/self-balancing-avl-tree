#pragma once
// FILE: AVLTree.h
// CLASS PROVVIDED: AVLTree

#include <iostream>

using namespace std;

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

	/// @brief recursive function that traverses tree and inserts key respectively
	/// @param key key to be inserted 
	/// @param current reference to current node 
	/// @return boolean whether or not key was succesfully inserted
	bool insertHelper(int key, Node*& current);

public:
	/// @brief AVLTree constructor
	AVLTree();

	/// @brief public insert function. makes recursive call to input helper
	/// @param key value to be inserted
	/// @return bool value if inserted succsesfully or not
	bool insert(int key);
};