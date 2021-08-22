#include "../inc/Linkedlist.hpp"

template <typename T>
myLinkedList<T>::myLinkedList() {
	this->head = NULL;
	this->tail = NULL;
}

template <typename T>
myLinkedList<T>::~myLinkedList() {
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
_node<T> *myLinkedList<T>::append(const T& value) {
	_node<T> *node = new _node<T>();
	node->value = value;
	node->next = NULL;

	if (this->head == NULL) {
		this->head = node;
		this->tail = node;
	} else {
		this->tail->next = node;
		this->tail = node;
	}

	return node;
}

template <typename T>
_node<T> *myLinkedList<T>::prepend(const T& value) {
	_node<T> *node = new _node<T>();
	node->value = value;
	node->next = NULL;

	if (this->head == NULL) {
		this->head = node;
		this->tail = node;
	} else {
		node->next = this->head;
		this->head = node;
	}

	return node;
}

template <typename T>
_node<T> *myLinkedList<T>::insert(int pos, const T& value) {
	if (pos == 0)
		return prepend(value);

	for (_node<T> *iter = this->head; iter ; iter=iter->next) {
		if (!(--pos)) {
			_node<T> *node = new _node<T>();
			node->value = value;
			node->next = iter->next;
			iter->next = node;
			return node;
		}
	}

	throw "pos is outside list";
	return NULL;
}

template <typename T>
void myLinkedList<T>::print() {
	_node<T> *node = this->head;
	do
	{
		cout << node->value << " ";
	} while ((node = node->next) != NULL);
	cout << endl;
}

template class myLinkedList<int>;
template class myLinkedList<string>;
