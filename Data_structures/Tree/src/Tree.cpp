#include "../inc/Tree.hpp"

template <typename T>
bool myTree<T>::_empty() {
	return !this->_root;
}

template <typename T>
myTree<T>::myTree() {
	this->_root = nullptr;
}

template <typename T>
myTree<T>::~myTree() {
}

template <typename T>
void myTree<T>::remove(const T& value) {
}

template <typename T>
node<T> *myTree<T>::getRoot() {
	return this->_root;
}
template <typename T>
void myTree<T>::insert(const T& value) {
	node<T> *_node = new node<T>(value);
	node<T> *prevNode = nullptr, *currNode = this->_root;


	if (_empty()) {
		this->_root = _node;
		return;
	}

	while (true) {
		if (value > currNode->value) {
			if (currNode->right == nullptr) {
				currNode->right = _node;
				break;
			}
			currNode = currNode->right;
		}
		else if (_node->value < currNode->value) {
			if (currNode->left == nullptr) {
				currNode->left = _node;
				break;
			}
			currNode = currNode->left;
		}
		else {
			cout << "value is existed -> do nothing";
			break;
		}
	}
}

template <typename T>
void myTree<T>::print() {
	if (!_empty())
		return;
}

template class myTree<int>;
template class myTree<string>;
