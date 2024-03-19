#include "AVLTree.h"

AVLTree::AVLTree() {
	root = nullptr;
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
	if (!current->right && !current->left) {
		current->height = current->height;
	}
	else if (!current->left) {
		current->height = current->right->height + 1;
	}
	else if (!current->right) {
		current->height = current->left->height + 1;
	}
	else {
		if (current->left->height > current->right->height) {
			current->height = current->left->height + 1;
		}
		else if (current->left->height < current->right->height) {
			current->height = current->right->height + 1;
		}
		else {
			current->height = current->left->height + 1;
		}
	}

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
