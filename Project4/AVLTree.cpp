#include "AVLTree.h"

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

// insert:
// Returns:
// Paramaters: 
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
	// code to recalculate height of current node 
	current->calcHeight();

	// Check my balance and rotate if necesarry

	return returnVal;
}

// getHeight: 
// Returns: height of AVLTree (int)
// Parameters: none
int AVLTree::getHeight() {
	return root->height;
}

// getSize: 
// Returns: size of AVLTree based on number of nodes (int)
// Parameters: none
int AVLTree::getSize() {
	return 0;
}

// find:
// Returns:
// Paramters:
bool AVLTree::find(int key, string& value) {
	if (key == root->key) {
		value = root->value;
		return true;
	}
	else if (key > root->key) {
		// sets current pointer equal to roots right child if key param is greater than roots key
		Node* current = root->right;

		// code to search both children of current node in O(log n) time 
	}
	else if (key < root->key) {
		// sets current pointer equal to roots left child if key param is less than roots key
		Node* current = root->left;

		// code to search both children of current node in O(log n) time 
	}
}

// findRange:
// Returns:
// Parameters:
vector<string> findRange(int lowkey, int highkey) {
	vector<string> hi;
	return hi;
}