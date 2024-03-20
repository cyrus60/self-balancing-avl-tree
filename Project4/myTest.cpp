#include "AVLTree.h"

int main() {
	AVLTree t;
	t.insert(10, "Ten");
	t.insert(9, "Nine");
	t.insert(8, "Eight");
	t.insert(11, "Eleven");
	t.insert(12, "Twelve");
	t.insert(7, "Seven");
	t.insert(13, "Thirteen");
	t.insert(14, "Fourteen");
	t.insert(15, "Fifteen");
	t.insert(16, "Sixteen");
	cout << t.getHeight() << endl;
}