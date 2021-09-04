#include "../inc/Graph.hpp"

myGraph::myGraph() {
	this->adjacentList = new unordered_map<int, unordered_set<int> *>();
	this->numOfNodes = 0;
}

myGraph::~myGraph() {
	if (this->adjacentList) {
		for (auto key: *this->adjacentList)
			delete key.second;
		delete this->adjacentList;
	}
	this->numOfNodes = 0;
}

void myGraph::addVertex(const int& value) {
	unordered_set<int> *adjacency = new unordered_set<int>();
	this->adjacentList->insert(make_pair(value, adjacency));
}

void myGraph::addEdge(const int& nodeValue1st, const int& nodeValue2nd) {
	if (!this->adjacentList) return;

	this->adjacentList->at(nodeValue1st)->insert(nodeValue2nd);
	this->adjacentList->at(nodeValue2nd)->insert(nodeValue1st);
}

void myGraph::print() {
	for (auto node: *this->adjacentList) {
		cout << node.first << ":";
		for (auto adjacency: *node.second)
			cout << " " << adjacency;
		cout << endl;
	}
}