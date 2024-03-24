#include "AVLTree.h"
#include <vector>

int main() {
	AVLTree t;
	t.insert(5, "Five");
	t.insert(4, "Four");
	t.insert(6, "Six");
	t.insert(7, "Seven");
	t.insert(8, "Eight");
	cout << t.root->key << endl;
}