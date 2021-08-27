#include <iostream>
#include <Queue.hpp>

using namespace std;

int main()
{
	try {
		linkedListQueue<string> list;
		list.enqueue("Joy");
		list.enqueue("Matt");
		list.enqueue("Marvel");
		list.enqueue("Samir");
		list.print();
		cout << list.seek() << endl;
		list.dequeue();
		list.print();
	} catch (char const *msg) {
		cerr << msg << endl;
	}
	return 0;
}
