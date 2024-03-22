#include "AVLTree.h"
#include <vector>

int main() {
	AVLTree t;
	t.insert(40, "Forty");
	t.insert(20, "Twenty");
	t.insert(10, "Ten");
	t.insert(30, "Thirty");
	t.insert(50, "Fifty");
	t.insert(45, "Forty-five");
	vector<string> vals = t.findRange(30, 47);
	for (string s : vals) {
		cout << s << endl;
	}
}