#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <string>
#include <iostream>

using namespace std;

template <typename T>
struct node {
	struct node *left;
	struct node *right;
	T value;
};

template <typename T>
class nodeClass {
private:
	struct node<T> *node;
public:
	nodeClass(const T& value) {
		node = new struct node<T>();
		node->left = NULL;
		node->right = NULL;
		node->value = value;
	}
	~nodeClass() {
		delete node;
	}
};

template <typename T>
using _node = struct nodeClass<T>;

template <typename T>
class myTree
{
private:
	_node<T> *root;
	bool _empty();

public:
	myTree();
	~myTree();
	void insert(const T& value);
	void remove(const T& value);
	void print();
};

#endif
