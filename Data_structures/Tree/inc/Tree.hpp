#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <string>
#include <iostream>

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

public:
	myTree();
	~myTree();
	void insert(const T& value);
	void remove(const T& value);
	bool lookup(const T& value);
	node<T> *getRoot();
	void print();
};

template <typename T>
using binaryTree = class myTree<T>;

#endif
