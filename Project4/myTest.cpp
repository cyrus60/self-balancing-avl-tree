#include "AVLTree.h"
#include <vector>

int main() {
	AVLTree t;
	t.insert(5, "Five");
	t.insert(4, "Four");
	t.insert(9, "Nine");
	t.insert(8, "Eight");
	t.insert(10, "Ten");
	t.insert(11, "Eleven");
	cout << t.root->key << endl;
}