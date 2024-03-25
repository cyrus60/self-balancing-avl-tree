#pragma once
// FILE: AVLTree.h
// CLASS PROVIDED: AVLTree

#include <iostream>
#include <vector>

using namespace std;

class AVLTree {
	// defines class for AVLTree nodes that will contain a key, value, a height, and left/right pointers
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
		/// @param none
		/// @return none
		void calcHeight();

		/// @brief calculates balance of current node
		/// @param none
		/// @return int balance factor of node
		int balanceFactor();
	};

	// pointer to the root of the AVLTree
	

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
	/// @brief AVLTree constructor
	Node* root;

	AVLTree();

	/// @brief AVLTree copy constructor
	AVLTree(const AVLTree& t);

	/// @brief size field keeping track of tree size in terms of total nodes
	int size;

	/// @brief public insert function. makes recursive call to input helper
	/// @param key of key value pair
	/// @param value value of key value pair
	/// @return bool value if inserted succsesfully or not
	bool insert(int key, string value);

	/// @brief
	/// @param
	/// @return
	int getHeight();

	/// @brief
	/// @param
	/// @return
	int getSize();

	/// @brief
	/// @param
	/// @return
	bool find(int key, string& value);

	/// @brief
	/// @param
	/// @return
	vector<string> findRange(int lowkey, int highkey);

	/// @brief
	/// @param
	/// @return
	friend ostream& operator<<(ostream& os, const AVLTree& me);

	/// @brief
	/// @param
	/// @return
	AVLTree& operator=(const AVLTree& t);

	/// @brief
	/// @param
	/// @return
	void rightRotate(Node*& problem);

	/// @brief
	/// @param
	/// @return
	void leftRotate(Node*& problem);
};