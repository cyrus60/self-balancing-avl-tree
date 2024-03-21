#include "AVLTree.h"
#include <iostream>

AVLTree::AVLTree() {
	root = nullptr;
}

// calcHeight:
// Returns:
// Paramaters:
void AVLTree::Node::calcHeight() {
	if (!right && !left) {
		height = height;
	}
	else if (!left) {
		height = right->height + 1;
	}
	else if (!right) {
		height = left->height + 1;
	}
	else {
		if (left->height > right->height) {
			height = left->height + 1;
		}
		else if (left->height < right->height) {
			height = right->height + 1;
		}
		else {
			height = left->height + 1;
		}
	}
}

// insert: calls recursive function insertHelper
// Returns: whether or not key value pair was inserted succesfully (bool)
// Paramaters: 
//		key (int) - key of key-value pair to be inserted
//		value (string) - value of key-value pair to be inserted
bool AVLTree::insert(int key, string value) {
	return insertHelper(key, value, root);
}

// insertHelper: recursive insert function called from insert
// Returns: Whether or not the insert was successful or not (bool)
// Parameters: 
//		key (int) - key of key value pair
//		value (string) - value of key value pair
//		current (Node*&) - reference to current Node
bool AVLTree::insertHelper(int key, string value, Node*& current) {
	bool returnVal;

	if (!current) {
		current = new Node(key, value);
		returnVal = true;
	}
	else if (current->key == key) {
		returnVal = false;
	}
	else if (current->key > key) {
		returnVal = insertHelper(key, value, current->left);
	}
	else {
		returnVal = insertHelper(key, value, current->right);
	}
	// recalculates height of current node 
	current->calcHeight();

	// Check my balance and rotate if necesarry
	

	return returnVal;
}

// insertHelper: recursive find function called from find
// Returns: Whether or not the given key was found in the tree or not 
// Parameters: 
//		key (int) - key of key value pair
//		value (string) - value of key value pair
//		current (Node*&) - reference to current Node
bool AVLTree::findHelper(int key, string& value, Node*& current) {
	if (current == nullptr) {
		return false;
	}
	else if (current->key == key) {
		value = current->value;
		return true;
	}
	else if (key < current->key) {
		return findHelper(key, value, current->left);
	}
	else {
		return findHelper(key, value, current->right);
	}
}

// getHeight: returns height of tree
// Returns: height of AVLTree (int)
// Parameters: none
int AVLTree::getHeight() {
	return root->height;
}

// getSize: traverses tree recursively and counts number of nodes
// Returns: size of AVLTree based on number of nodes (int)
// Parameters: none
int AVLTree::getSize() {
	return 0;
}

// find: calls recursive function findHelper
// Returns: Whether or not the key was found in the tree (bool)
// Paramaters:
//		key (int) - key of key value pair
//		value (string&) - reference to string that value of key will be stored in
bool AVLTree::find(int key, string& value) {
	return findHelper(key, value, root);
}

// findRange:
// Returns:
// Parameters:
vector<string> findRange(int lowkey, int highkey) {
	vector<string> hi;
	return hi;
}