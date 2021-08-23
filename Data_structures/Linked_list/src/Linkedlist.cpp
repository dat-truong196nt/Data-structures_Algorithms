#include "../inc/Linkedlist.hpp"

template <typename T>
void myLinkedList<T>::_switchHeadTail() {
	_node<T> *head = this->head;
	this->head = this->tail;
	this->tail = head;
}

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
void myLinkedList<T>::remove(int pos) {
	if (pos < 0) return;

	if (pos == 0) {
		if (this->head == this->tail) {
			delete this->head;
			this->head = NULL;
			this->tail = NULL;
		} else {
			_node<T> *head = this->head;
			this->head = this->head->next;
			delete head;
			return;
		}
	}

	_node<T> *prev = NULL;
	for (_node<T> *iter = this->head; iter != NULL ; iter=iter->next) {
		if (!(pos--)) {
			prev->next = iter->next;
			delete iter;
			return;
		}
		prev = iter;
	}

}

template <typename T>
_node<T> *myLinkedList<T>::insert(int pos, const T& value) {
	if (pos == 0)
		return prepend(value);

	for (_node<T> *iter = this->head; iter !=NULL ; iter=iter->next) {
		if (!(--pos)) {
			_node<T> *node = new _node<T>();
			node->value = value;
			node->next = iter->next;
			iter->next = node;
			return node;
		}
	}

	return append(value);
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


template <typename T>
void myLinkedList<T>::reverse() {
	_switchHeadTail();
	_node<T> *curr = this->tail;
	_node<T> *prev = curr->next;
	_node<T> *next = NULL;

	do {
		prev = curr->next;
		curr->next = next;
		next = curr;
		curr = prev;
	} while(curr != NULL);
}

template class myLinkedList<int>;
template class myLinkedList<string>;
