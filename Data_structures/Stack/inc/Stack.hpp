#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <string>
#include <iostream>

using namespace std;

template <typename T>
struct node {
	struct node *next;
	T value;
};
template <typename T>
using _node = struct node<T>;

template <typename T>
class _stack
{
private:
	_node<T> *bottom;
	_node<T> *top;
	bool _empty();

public:
	_stack();
	~_stack();
	_node<T> *push(const T& value);
	void pop();
	T seek();
	void print();
};

template <typename T>
using linkedListStack = class _stack<T>;

#endif
