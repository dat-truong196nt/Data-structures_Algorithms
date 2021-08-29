#include <iostream>
#include <Tree.hpp>

using namespace std;

int main()
{
	try {
		binaryTree<int> myTree;
		myTree.insert(9);
		myTree.insert(4);
		myTree.insert(6);
		myTree.insert(20);
		myTree.insert(170);
		myTree.insert(15);
		myTree.insert(1);
		cout << myTree.getRoot()->right->right->value;
		cout << myTree.getRoot()->left->left->value;
	} catch (char const *msg) {
		cerr << msg << endl;
	}
	return 0;
}
