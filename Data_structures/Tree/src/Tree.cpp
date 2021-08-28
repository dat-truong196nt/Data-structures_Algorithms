#include "../inc/Tree.hpp"

template <typename T>
bool myTree<T>::_empty() {
	return !this->root;
}

template <typename T>
myTree<T>::myTree() {
	this->root = nullptr;
}

template <typename T>
myTree<T>::~myTree() {
}

template <typename T>
void myTree<T>::remove(const T& value) {
}

template <typename T>
void myTree<T>::insert(const T& value) {
	_node<T> *node = new _node<T>(value);
	_node<T> *traversalNode = this->root;

	if (_empty())
		this->root = nullptr;

	// if (node->value > traversalNode->value) {

	// }
	// else if (node->value < traversalNode->value) {

	// }
	// else {
	// 	cout << "value is existed -> do nothing";
	// }
}

template <typename T>
void myTree<T>::print() {
	if (!_empty())
		return;
}

template class myTree<int>;
template class myTree<string>;
