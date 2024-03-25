#include "AVLTree.h"
#include <iostream>

// AVLTree: main constructor
AVLTree::AVLTree() {
	root = nullptr;
	size = 0;
}

// AVLTree: copy constructor
// Paramaters
//		t (AVLTree&) - reference to AVLTree being copied
AVLTree::AVLTree(const AVLTree& t) {

}

// leftRotate: performs a right rotation at current node
// Returns: none
// Paramaters: 
//		problem (Node*&) - pointer to problem node 
void AVLTree::leftRotate(Node*& problem) {
	// setting hook node as problem nodes right child
	Node* hook = problem->right;
	// setting a tempPointer to problem node 
	Node* problemTemp = problem;

	// setting temp pointer to hooks left child if one exists
	if (hook->left) {
		Node* temp = hook->left;

		problem = hook;
		hook->left = problemTemp;
		problemTemp->right = temp;
	}
	// if hook doesn't have left child, set hooks left child equal to problem node
	else {
		problem = hook;
		hook->left = problemTemp;
		problemTemp->right = nullptr;
	}

	// if root key and problem key are the same, hook is root
	if (root->key == problem->key) {
		root = hook;
	}

	// recalculate heights 
	problemTemp->calcHeight();
	hook->calcHeight();
}

// rightRotate: performs a right rotation at current node
// Returns: none
// Paramaters: 
//		problem (Node*&) - pointer to problem node 
void AVLTree::rightRotate(Node*& problem) {
	// setting hook node as problem nodes left child
	Node* hook = problem->left;
	// setting a tempPointer to problem node 
	Node* problemTemp = problem;

	// setting temp pointer to hooks right child if one exists
	if (hook->right) {
		Node* temp = hook->right;

		problem = hook;
		hook->right = problemTemp;
		problemTemp->left = temp;
	}
	// if hook doesn't have right child, set hooks right child equal to problem node
	else {
		problem = hook;
		hook->right = problemTemp;
		problemTemp->left = nullptr;

	}

	// if root key and problem key are the same, hook is root
	if (root->key == problem->key) {
		root = hook;
	}

	// recalculate heights 
	problemTemp->calcHeight();
	hook->calcHeight();
}


// calcHeight: calulates height of current node 
// Returns: none
// Paramaters: none
void AVLTree::Node::calcHeight() {
	// if right and left child are null, height = 0
	if (!right && !left) {
		height = 0;
	}
	else if (!left) {
		height = right->height + 1;
	}
	else if (!right) {
		height = left->height + 1;
	}
	// if node has both right and left child, set height equal to the greater height of the two nodes
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
	// balance is zero if right and left are null
	if (!left && !right) {
		return 0;
	}
	else if (!right) {
		return left->height + 1;
	}
	else if (!left) {
		return (0 - (right->height + 1));
	}
	// if Node has both left and right, balance equals left height minus right height
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

	// if current Node is null, set current equal to new Node
	if (!current) {
		current = new Node(key, value);
		returnVal = true;

		// if tree is empty, current is root
		if (size == 0) {
			root = current;
		}
	}
	// if key parameter equals current Node's key, return false (no duplicates)
	else if (current->key == key) {
		returnVal = false;
	}
	// if current Node's key is greater than key parameter, recursive call on left child
	else if (current->key > key) {
		returnVal = insertHelper(key, value, current->left);
	}
	// recursive call on right child otherwise
	else {
		returnVal = insertHelper(key, value, current->right);
	}
	// recalculates height of current node 
	current->calcHeight();

	// Check my balance and rotate if necesarry
	int balance = current->balanceFactor();

	// if balance of current node is greater than one, set hook pointer equal to currents left child and rotate
	if (balance > 1) {
		Node* hook = current->left;

		// if problem node and hook node have opposite-sign balance factors, double rotate
		if (hook->balanceFactor() < 0) {
			Node* newHook = current->left->right;
			leftRotate(hook);
			current->left = newHook;
			rightRotate(current);
		}
		// if problem node and hook node balance factors are same sign, right rotate
		else {
			rightRotate(current);
		}
	}
	// if balance of current node is less than negative one, set hook pointer equal to currents right child and rotate 
	else if (balance < -1) {
		Node* hook = current->right;

		// if problem node and hook node have opposite-sign balance factors, double rotate
		if (hook->balanceFactor() > 0) {
			Node* newHook = current->right->left;
			rightRotate(hook);
			current->right = newHook;
			leftRotate(current);
		}
		// if problem node and hook node balance factors are same sign, left rotate
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
	// base case
	if (!current) {
		return false;
	}
	// if keys are equal, set value reference equal to current Node's value
	else if (current->key == key) {
		value = current->value;
		return true;
	}
	// if key arg is less than current Node's key, recursive call on current's left child
	else if (key < current->key) {
		return findHelper(key, value, current->left);
	}
	// recursive call on current's right child if key arg is greater than current Node's key
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

// print: Prints out AVLTree sideways to demonstrate structure of the tree
// Returns:
// Parameters:
void print(ostream& os) {

}

// <<: Prints out AVLTree sideways to demonstrate structure of the tree
// Returns: 
// Parameters: 
//		os (ostream&) - output streeam to be used to print
//		tree (AVLTree&) - reference to AVLTree
ostream& operator<<(ostream& os, const AVLTree& t) {
	t.print(os);
	return os;
}

// =: creates and returns indpendant copy of AVLTree
// Returns: Reference to new AVLTree (AVLTree&)
// Parameters: 
//		t (AVLTree&) - reference to AVLTree being copied
AVLTree& AVLTree::operator=(const AVLTree& t) {
	AVLTree treeReturn;
	return treeReturn;
}