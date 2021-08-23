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
class myLinkedList
{
private:
	_node<T> *head;
	_node<T> *tail;
	void _switchHeadTail();
	bool _empty();

public:
	myLinkedList();
	~myLinkedList();
	_node<T> *append(const T& value);
	_node<T> *prepend(const T& value);
	_node<T> *insert(int pos, const T& value);
	void remove(int pos);
	void print();
	void reverse();
};

#endif
