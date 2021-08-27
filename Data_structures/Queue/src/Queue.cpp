#include "../inc/Queue.hpp"

template <typename T>
bool _queue<T>::_empty() {
	return !this->first;
}

template <typename T>
_queue<T>::_queue() {
	this->first = NULL;
	this->last = NULL;
}

template <typename T>
_queue<T>::~_queue() {
	if (this->last == NULL)
		return;

	_node<T> *curr = this->first;
	_node<T> *next = curr->next;
	while (next)
	{
		delete(curr);
		curr = next;
		next = next->next;
	}
}

template <typename T>
_node<T> *_queue<T>::enqueue(const T& value) {
	_node<T> *node = new _node<T>();
	node->value = value;
	node->next = NULL;

	if (_empty()) {
		this->first = node;
		this->last = node;
	} else {
		this->last->next = node;
		this->last = node;
	}

	return node;
}

template <typename T>
void _queue<T>::dequeue() {
	if (_empty())
		return;

	if (this->first == this->last) {
		delete this->first;
		this->first = NULL;
		this->last = NULL;
		return;
	}

	_node<T> *nextFirst = this->first->next;
	delete this->first;
	this->first = nextFirst;
}

template <typename T>
T _queue<T>::seek() {
	return this->first->value;
}

template <typename T>
void _queue<T>::print() {
	if (_empty())
		return;

	_node<T> *node = this->first;
	do
	{
		cout << node->value << " ";
	} while ((node = node->next) != NULL);
	cout << endl;
}

template class _queue<int>;
template class _queue<string>;
