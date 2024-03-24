#include "AVLTree.h"
#include <iostream>

AVLTree::AVLTree() {
	root = nullptr;
	size = 0;
}

// leftRotate: performs a right rotation at current node
// Returns: none
// Paramaters: 
//		problem (Node*) - pointer to problem node 

void AVLTree::leftRotate(Node* problem) {
	// setting hook node as problem nodes right child
	Node* hook = problem->right;

	// setting temp pointer to hooks left child if one exists
	if (hook->left) {
		Node* temp = hook->left;

		hook->left = problem;
		problem->right = temp;
	}
	// if hook doesn't have left child, set hooks left child equal to problem node
	else {
		hook->left = problem;
		problem->right = nullptr;

		if (root->key == problem->key) {
			root = hook;
		}
	}

	// recalculate heights 
	hook->calcHeight();
	problem->calcHeight();
}

// rightRotate: performs a right rotation at current node
// Returns: none
// Paramaters: 
//		problem (Node*) - pointer to problem node 
void AVLTree::rightRotate(Node* problem) {
	// setting hook node as problem nodes left child
	Node* hook = problem->left;

	// setting temp pointer to hooks right child if one exists
	if (hook->right) {
		Node* temp = hook->right;

		hook->right = problem;
		problem->left = temp;
	}
	// if hook doesn't have right child, set hooks right child equal to problem node
	else {
		hook->right = problem;
		problem->left = nullptr;

		if (root->key == problem->key) {
			root = hook;
		}
	}

	// recalculate heights 
	hook->calcHeight();
	problem->calcHeight();
}


// calcHeight: calulates height of current node 
// Returns: none
// Paramaters: none
void AVLTree::Node::calcHeight() {
	if (!right && !left) {
		height = 0;;
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

// balanceFactor: calulates balance of current node 
// Returns: balance of current node (int)
// Paramaters: none
int AVLTree::Node::balanceFactor() {
	if (!left && !right) {
		return 0;
	}
	else if (!right) {
		return left->height + 1;
	}
	else if (!left) {
		return (0 - (right->height + 1));
	}
	else {
		return (left->height + 1) - (right->height + 1);
	}
}

// insert: calls recursive function insertHelper
// Returns: whether or not key value pair was inserted succesfully (bool)
// Paramaters: 
//		key (int) - key of key-value pair to be inserted
//		value (string) - value of key-value pair to be inserted
bool AVLTree::insert(int key, string value) {
	bool success = insertHelper(key, value, root);

	if (success) {
		size += 1;
	}

	return success;
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

		if (size == 0) {
			root = current;
		}
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
	int balance = current->balanceFactor();

	if (balance > 1) {
		Node* hook = current->left;

		if (hook->balanceFactor() < 0) {

		}
		else {
			rightRotate(current);
		}
	}
	else if (balance < -1) {
		Node* hook = current->right;

		if (hook->balanceFactor() > 0) {

		}
		else {
			leftRotate(current);
		}

	}

	return returnVal;
}

// findHelper: recursive find function called from find
// Returns: Whether or not the given key was found in the tree or not 
// Parameters: 
//		key (int) - key of key value pair
//		value (string) - value of key value pair
//		current (Node*&) - reference to current Node
bool AVLTree::findHelper(int key, string& value, Node*& current) {
	if (!current) {
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

// findRangeHelper: Recursive findRange function called from findRange
// Returns: Whether or not the given key was found in the tree or not 
// Parameters: 
//		key (int) - key of key value pair
//		value (string) - value of key value pair
//		current (Node*&) - reference to current Node
void AVLTree::findRangeHelper(int lowkey, int highkey, vector<string>& vals, Node* current) {
	if (current) {
		findRangeHelper(lowkey, highkey, vals, current->left);

		if (current->key >= lowkey && current->key <= highkey) {
			vals.push_back(current->value);
		}

		findRangeHelper(lowkey, highkey, vals, current->right);
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
	return size;
}

// find: calls recursive function findHelper
// Returns: Whether or not the key was found in the tree (bool)
// Paramaters:
//		key (int) - key of key value pair
//		value (string&) - reference to string that value of key will be stored in
bool AVLTree::find(int key, string& value) {
	return findHelper(key, value, root);
}

// findRange: Finds and returns all values between specified keys
// Returns: Vector of all values in range (vector<string>)
// Parameters: 
//		lowkey (int) - low bound of search range
//		highkey (int) - upper bound of search range
vector<string> AVLTree::findRange(int lowkey, int highkey) {
	vector<string> vals;
	findRangeHelper(lowkey, highkey, vals, root);

	return vals;
}

// <<: Prints out AVLTree sideways to demonstrate structure of the tree
// Returns: 
// Parameters: 
//		os (ostream&) - output streeam to be used to print
//		tree (AVLTree&) - reference to AVLTree
ostream& operator<<(ostream& os, const AVLTree& tree) {
	return os;
}