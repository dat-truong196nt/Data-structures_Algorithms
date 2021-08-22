#include <iostream>
#include <Linkedlist.hpp>

using namespace std;

int main()
{
	try {
	class myLinkedList<string> list;
	list.prepend("Truong");
	list.prepend("Quoc");
	list.prepend("Dat");
	list.insert(4, "ok");
	list.print();
	} catch (char const *msg) {
		cerr << msg << endl;
	}
	return 0;
}
