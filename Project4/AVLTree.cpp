#include "AVLTree.h"

AVLTree::AVLTree() {
	root = nullptr;
}

bool AVLTree::insert(int key) {
	return insertHelper(key, root);
}

// insertHelper: recursive insert function called from insert
// Returns: Whether or not the insert was successful or not (bool)
// Parameters: 
//		key (int) - key to be inserted
//		current (Node*&) - reference to current Node
bool AVLTree::insertHelper(int key, Node*& current) {
	bool returnVal;
	if (!current) {
		current = new Node(key);
		returnVal = true;
	}
	else if (current->key == key) {
		returnVal = false;
	}
	else if (current->key > key) {
		returnVal = insertHelper(key, current->left);
	}
	else {
		returnVal = insertHelper(key, current->right);
	}
	// code to recalculate height of current node 

	// Check my balance and rotate if necesarry

	return returnVal;
}