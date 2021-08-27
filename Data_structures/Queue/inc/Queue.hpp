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
class _queue
{
private:
	_node<T> *first;
	_node<T> *last;
	bool _empty();

public:
	_queue();
	~_queue();
	_node<T> *enqueue(const T& value);
	void dequeue();
	T seek();
	void print();
};

template <typename T>
using linkedListQueue = class _queue<T>;

#endif
