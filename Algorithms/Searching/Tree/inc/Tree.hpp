#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <string>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

template <typename T>
class nodeClass {
public:
	class nodeClass *left;
	class nodeClass *right;
	T value;
	nodeClass(const T& value) {
		this->left = NULL;
		this->right = NULL;
		this->value = value;
	}
	~nodeClass() {
	}
};

template <typename T>
using node = struct nodeClass<T>;

template <typename T>
class myTree
{
private:
	node<T> *_root;
	bool _empty();
	vector<T> _breadthFirstSearchIterate(vector<node<T> *> &parent);
	vector<T> _DFSInOrder(node<T> *node, vector<T> &valueList);
	vector<T> _DFSPreOrder(node<T> *node, vector<T> &valueList);
	vector<T> _DFSPostOrder(node<T> *node, vector<T> &valueList);

public:
	myTree();
	~myTree();
	void insert(const T& value);
	void remove(const T& value);
	bool lookup(const T& value);
	void breadthFirstSearchV1();
	void breadthFirstSearchV2();
	void breadthFirstSearchRecursive(vector<node<T> *> &nodeList, int _index);
	vector<T> breadthFirstSearchRecursiveV2(vector<node<T> *> nodeList, vector<T> valueList);
	vector<T> DFSInOrder();
	vector<T> DFSPreOrder();
	vector<T> DFSPostOrder();
	node<T> *getRoot();
	void print();
};

template <typename T>
using binaryTree = class myTree<T>;

#endif
