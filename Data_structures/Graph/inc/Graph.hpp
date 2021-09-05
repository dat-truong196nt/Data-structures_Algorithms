#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

class myGraph
{
private:
	unordered_map<int, unordered_set<int> *> *adjacentList;
	int numOfNodes;

public:
	myGraph();
	~myGraph();
	void addVertex(const int& value);
	void addEdge(const int& nodeValue1st, const int& nodeValue2nd);
	void print();
};

#endif
