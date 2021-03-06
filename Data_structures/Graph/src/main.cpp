#include <iostream>
#include <Graph.hpp>

using namespace std;

int main()
{
	try {
		class myGraph myGraph;
		myGraph.addVertex(0);
		myGraph.addVertex(1);
		myGraph.addVertex(2);
		myGraph.addVertex(3);
		myGraph.addVertex(4);
		myGraph.addVertex(5);
		myGraph.addVertex(6);
		myGraph.addEdge(3, 1);
		myGraph.addEdge(3, 4);
		myGraph.addEdge(4, 2);
		myGraph.addEdge(4, 5);
		myGraph.addEdge(1, 2);
		myGraph.addEdge(1, 0);
		myGraph.addEdge(0, 2);
		myGraph.addEdge(6, 5);
		myGraph.print();
		// *Result: in any order
		// 6: 5
		// 5: 6 4
		// 4: 5 2 3
		// 3: 4 1
		// 2: 0 1 4
		// 1: 0 2 3
		// 0: 2 1
	} catch (char const *msg) {
		cerr << msg << endl;
	}
	return 0;
}
