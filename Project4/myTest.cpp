#include "AVLTree.h"
#include <vector>

int main() {
	AVLTree t;
	t.insert(5, "Five");
	t.insert(6, "Six");
	t.insert(7, "Seven");
	cout << t.root->key << endl;
}