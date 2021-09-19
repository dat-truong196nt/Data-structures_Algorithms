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
		myTree.insert(30);
		myTree.insert(7);
		myTree.insert(3);
		myTree.insert(120);
		vector<int> output = myTree.breadthFirstSearchI();
		for (auto item: output)
			cout << item << " ";
		cout << endl;
	} catch (char const *msg) {
		cerr << msg << endl;
	}
	return 0;
}
