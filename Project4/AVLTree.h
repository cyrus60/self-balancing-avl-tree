#pragma once
// FILE: AVLTree.h
// CLASS PROVIDED: AVLTree

#include <iostream>
#include <vector>

using namespace std;

class AVLTree {
	// defines class for AVLTree Nodes that will contain a key, value, a height, and left/right pointers
private:
	class Node {
	public:
		int key;
		string value;
		int height = 0;
		Node* left = nullptr;
		Node* right = nullptr;
		Node(int newKey, string newVal) : key(newKey), value(newVal), left(nullptr), right(nullptr) {}

		/// @brief calculates height of current Node 
		void calcHeight();

		/// @brief calculates balance of current node
		/// @return int balance factor of node
		int balanceFactor();
	};

	/// @brief recursive function that traverses tree and inserts key respectively
	/// @param key key of key value pair
	/// @param value value og key value pair
	/// @param current reference to current node 
	/// @return boolean whether or not key was succesfully inserted
	bool insertHelper(int key, string value, Node*& current);

	/// @brief recursive function that traverses tree and finds any nodes with the same key as the one given
	/// @param key key of key value pair
	/// @param value reference to value item associated with the key 
	/// @param current reference to current node 
	/// @return boolean whether or not key was succesfully found
	bool findHelper(int key, string& value, Node*& current);

	/// @brief recursive function that traverses tree and finds any nodes with the same key as the one given
	/// @param key key of key value pair
	/// @param value reference to value item associated with the key 
	/// @param current reference to current node 
	/// @return boolean whether or not key was succesfully found
	void findRangeHelper(int lowkey, int highkey, vector<string>& vals, Node* current);

public:
	// pointer to the root of the AVLTree
	Node* root;

	/// @brief AVLTree constructor
	AVLTree();

	/// @brief AVLTree copy constructor
	/// @param const AVLTree& t reference to AVLTree being copied
	AVLTree(const AVLTree& t);

	/// @brief tree destructor
	~AVLTree();

	/// @brief recursive delete function
	void eraseNodes(Node* current);

	/// @brief size field keeping track of tree size in terms of total nodes
	int size;

	/// @brief public insert function. makes recursive call to input helper
	/// @param key of key value pair
	/// @param value value of key value pair
	/// @return bool value if inserted succsesfully or not
	bool insert(int key, string value);

	/// @brief returns total height of AVLTree
	/// @return int height of tree
	int getHeight();

	/// @brief returns total size of AVLTree in terms of total nodes
	/// @return int value, number of nodes
	int getSize();

	/// @brief finds specified key in AVLTree and places it's value into the value parameter
	/// @param int key value to be searched for
	/// @param string& value reference to string that will contain keys value
	/// @return boolean value if Node was found or not
	bool find(int key, string& value);

	/// @brief finds values between a given range of keys
	/// @param int lowkey lower bound of search
	/// @param int highkey upper bound of search
	/// @return vector<string> containing value of keys between given range
	vector<string> findRange(int lowkey, int highkey);

	/// @brief print operator
	/// @param os outstream to be printed to
	/// @param t reference to AVLTree to print
	/// @return ostream reference to output stream
	friend ostream& operator<<(ostream& os, AVLTree& t);

	/// @brief recursive print function
	/// @param os reference to output stream to be printed 
	/// @param Node * current pointer to current Node object
	/// @param int depth keeps track of depth within tree when printing
	void print(ostream& os, Node* current, int depth);

	/// @brief assignment operator
	/// @param t reference to AVLTree to copy
	/// @return AVLTree& reference to copied AVLTree
	AVLTree& operator=(AVLTree& t);

	/// @brief rotates right
	/// @param problem Node*& reference to pointer of problem node
	void rightRotate(Node*& problem);

	/// @brief rotates left 
	/// @param problem Node*& reference to pointer of problem node
	void leftRotate(Node*& problem);

	/// @brief recursive copyHelp function traverses tree and inserts each node into the new tree
	/// @param current Node* pointer to current node
	/// newNode Node*& reference to new node
	void copyHelp(Node* current, Node*& newNode);
};