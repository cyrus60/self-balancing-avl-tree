#include "AVLTree.h"

int main() {
	AVLTree t;
	t.insert(10, "Ten");
	t.insert(9, "Nine");
	t.insert(8, "Eight");
	t.insert(11, "Eleven");
	cout << t.getHeight() << endl;
}