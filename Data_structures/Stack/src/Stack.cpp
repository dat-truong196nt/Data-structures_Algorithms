#include "../inc/Stack.hpp"

template <typename T>
bool _stack<T>::_empty() {
	return !this->head;
}

template <typename T>
void _stack<T>::_switchHeadTail() {
	_node<T> *head = this->head;
	this->head = this->tail;
	this->tail = head;
}

template <typename T>
_stack<T>::_stack() {
	this->head = NULL;
	this->tail = NULL;
}

template <typename T>
_stack<T>::~_stack() {
	if (this->head == NULL)
		return;

	_node<T> *curr = this->head;
	_node<T> *next = this->head->next;
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
	node->next = NULL;

	if (_empty()) {
		this->head = node;
		this->tail = node;
	} else {
		this->tail->next = node;
		this->tail = node;
	}

	return node;
}

template <typename T>
void _stack<T>::pop() {
	if (_empty())
		return;

	if (this->head == this->tail) {
		delete this->head;
		this->head = NULL;
		this->tail = NULL;
		return;
	}

	_node<T> *vLastNode = NULL;
	for (vLastNode = this->head; vLastNode->next != this->tail; vLastNode = vLastNode->next);
	delete this->tail;
	vLastNode->next = NULL;
	this->tail = vLastNode;
}

template <typename T>
T _stack<T>::seek() {
	return this->tail->value;
}

template <typename T>
void _stack<T>::print() {
	if (_empty())
		return;

	_node<T> *node = this->head;
	do
	{
		cout << node->value << " ";
	} while ((node = node->next) != NULL);
	cout << endl;
}

template class _stack<int>;
template class _stack<string>;
