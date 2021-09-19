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
bool myTree<T>::lookup(const T& value) {
	node<T> *_node = this->_root;
	if (_empty())
		return false;

	while (_node)
	{
		if (value > _node->value)
			_node = _node->right;
		else if (value < _node->value)
			_node = _node->left;
		else
			return true;
	}
	return false;
}

template <typename T>
vector<T> myTree<T>::_breadthFirstSearchIterate(vector<node<T> *> &parent) {
	vector<node<T> *> nextParent;
	vector<T> value;

	for (auto item: parent) {
		if (item->left) {
			nextParent.push_back(item->left);
			value.push_back(item->left->value);
		}
		if (item->right) {
			nextParent.push_back(item->right);
			value.push_back(item->right->value);
		}
	}

	parent = nextParent;
	return value;
}

template <typename T>
void myTree<T>::breadthFirstSearchV1() {
	// parent = root
	vector<node<T> *> parent;
	vector<T> value;
	parent.push_back(this->_root);
	value.push_back(this->_root->value);
	// find next parent
	while (parent.size()) {
		vector<T> child = _breadthFirstSearchIterate(parent);
		value.insert(value.end(), child.begin(), child.end());
	}
	// print child value
	for (auto item: value)
		cout << item << " ";
	cout << endl;
}
template <typename T>
void myTree<T>::breadthFirstSearchV2() {
	vector<node<T> *> nodeList;
	int _index = 0;
	nodeList.push_back(this->_root);

	while (_index < nodeList.size()) {
		if (nodeList.at(_index)->left)
			nodeList.push_back(nodeList.at(_index)->left);
		if (nodeList.at(_index)->right)
			nodeList.push_back(nodeList.at(_index)->right);
		_index++;
	}

	for (auto item: nodeList)
		cout << item->value << " ";
	cout << endl;
}

template <typename T>
void myTree<T>::breadthFirstSearchRecursive(vector<node<T> *> &nodeList, int _index) {
	// Ending point (left && right == empty)
	if (_index >= nodeList.size())
		return;

	// push left, push right
	if (nodeList.at(_index)->left) nodeList.push_back(nodeList.at(_index)->left);
	if (nodeList.at(_index)->right) nodeList.push_back(nodeList.at(_index)->right);

	// push recursive left, right
	breadthFirstSearchRecursive(nodeList, ++_index);
}
template <typename T>
vector<T> myTree<T>::breadthFirstSearchRecursiveV2(vector<node<T> *> nodeList, vector<T> valueList) {

	if (nodeList.empty())
		return valueList;

	valueList.push_back(nodeList.at(0)->value);
	if (nodeList.at(0)->left)
		nodeList.push_back(nodeList.at(0)->left);
	if (nodeList.at(0)->right)
		nodeList.push_back(nodeList.at(0)->right);
	nodeList.erase(nodeList.begin());

	return this->breadthFirstSearchRecursiveV2(nodeList, valueList);
}

template <typename T>
vector<T> myTree<T>::DFSPostOrder() {
	vector<T> valueList;
	return _DFSPostOrder(this->_root, valueList);
}

template <typename T>
vector<T> myTree<T>::_DFSPostOrder(node<T> *node, vector<T> &valueList) {
	// nodeList push node
	valueList.push_back(node->value);
	// nodeList push func(left, nodeList)
	if (node->left) _DFSPostOrder(node->left, valueList);
	// nodeList push right(right, nodeListleft)
	if (node->right) _DFSPostOrder(node->right, valueList);

	return valueList;
}

template <typename T>
vector<T> myTree<T>::DFSPreOrder() {
	vector<T> valueList;
	return _DFSPreOrder(this->_root, valueList);
}

template <typename T>
vector<T> myTree<T>::_DFSPreOrder(node<T> *node, vector<T> &valueList) {
	// nodeList push func(left, nodeList)
	if (node->left) _DFSPreOrder(node->left, valueList);
	// nodeList push right(right, nodeListleft)
	if (node->right) _DFSPreOrder(node->right, valueList);
	// nodeList push node
	valueList.push_back(node->value);

	return valueList;
}

template <typename T>
vector<T> myTree<T>::DFSInOrder() {
	vector<T> valueList;
	return _DFSInOrder(this->_root, valueList);
}

template <typename T>
vector<T> myTree<T>::_DFSInOrder(node<T> *node, vector<T> &valueList) {
	// nodeList push func(left, nodeList)
	if (node->left) _DFSInOrder(node->left, valueList);
	// nodeList push node
	valueList.push_back(node->value);
	// nodeList push right(right, nodeListleft)
	if (node->right) _DFSInOrder(node->right, valueList);

	return valueList;
}

template <typename T>
void myTree<T>::remove(const T& value) {
	// get prev, node matching value;
	pair<node<T> *, node<T> *> _node = make_pair(nullptr, nullptr);
	_node.second = this->_root;
	if (_empty())
		return;

	while (_node.second)
	{
		if (value > _node.second->value) {
			_node.first = _node.second;
			_node.second = _node.second->right;
		}
		else if (value < _node.second->value) {
			_node.first = _node.second;
			_node.second = _node.second->left;
		}
		else
			break;
	}

	if (!_node.second)
		return;
	if (_node.first) cout << _node.first->value << endl; // TODO: remove this
	if (_node.second) cout << _node.second->value << endl; // TODO: remove this

	// find replace node
	pair<node<T> *, node<T> *> _replaceNode = make_pair(nullptr, nullptr);
	// If right not null -> find node with value = min
	if (_node.second->right) {
		_replaceNode.first = _node.second;
		_replaceNode.second = _replaceNode.first->right;
		while (_replaceNode.second->right || _replaceNode.second->left) {
			_replaceNode.first = _replaceNode.second;
			_replaceNode.second = _replaceNode.second->left ? _replaceNode.second->left : _replaceNode.second->right;
		}
	}
	// if left not null -> find node with value = max
	else if (_node.second->left) {
		_replaceNode.first = _node.second;
		_replaceNode.second = _replaceNode.first->left;
		while (_replaceNode.second->right || _replaceNode.second->left) {
			_replaceNode.first = _replaceNode.second;
			_replaceNode.second = _replaceNode.second->right ? _replaceNode.second->right : _replaceNode.second->left;
		}
	}
	if (_replaceNode.first) cout << _replaceNode.first->value << endl; // TODO: remove this
	if (_replaceNode.second) cout << _replaceNode.second->value << endl; // TODO: remove this

	// replace with found node.
	if (!_replaceNode.first && !_replaceNode.second) {
		if (_node.first->right == _node.second) _node.first->right = nullptr;
		else _node.first->left = nullptr;
	}
	else {
		if (_replaceNode.first->right == _replaceNode.second) _replaceNode.first->right = nullptr;
		else _replaceNode.first->left = nullptr;

		if (!_node.first) {
			this->_root = _replaceNode.second;
		}
		else {
			if (_node.first->right == _node.second) _node.first->right = _replaceNode.second;
			else _node.first->left = _replaceNode.second;
		}

		_replaceNode.second->left = _node.second->left;
		_replaceNode.second->right = _node.second->right;
	}
	delete _node.second;
	cout << endl;
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
