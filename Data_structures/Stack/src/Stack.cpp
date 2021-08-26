#include "../inc/Stack.hpp"

template <typename T>
bool _stack<T>::_empty() {
	return !this->bottom;
}

template <typename T>
_stack<T>::_stack() {
	this->bottom = NULL;
	this->top = NULL;
}

template <typename T>
_stack<T>::~_stack() {
	if (this->top == NULL)
		return;

	_node<T> *curr = this->top;
	_node<T> *next = this->top->next;
	while (next)
	{
		delete(curr);
		curr = next;
		next = next->next;
	}
}

template <typename T>
_node<T> *_stack<T>::push(const T& value) {
	_node<T> *node = new _node<T>();
	node->value = value;
	node->next = this->top;

	if (_empty()) {
		this->bottom = node;
		this->top = node;
	} else {
		this->top = node;
	}

	return node;
}

template <typename T>
void _stack<T>::pop() {
	if (_empty())
		return;

	if (this->bottom == this->top) {
		delete this->bottom;
		this->bottom = NULL;
		this->top = NULL;
		return;
	}

	_node<T> *nextTop = this->top->next;
	delete this->top;
	this->top = nextTop;
}

template <typename T>
T _stack<T>::seek() {
	return this->top->value;
}

template <typename T>
void _stack<T>::print() {
	if (_empty())
		return;

	_node<T> *node = this->top;
	do
	{
		cout << node->value << " ";
	} while ((node = node->next) != NULL);
	cout << endl;
}

template class _stack<int>;
template class _stack<string>;
