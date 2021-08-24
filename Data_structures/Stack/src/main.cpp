#include <iostream>
#include <Stack.hpp>

using namespace std;

int main()
{
	try {
		myStack<string> list;
		list.push("Truong");
		list.push("Quoc");
		list.push("Dat");
		cout << list.seek() << endl;
		list.pop();
		list.print();
	} catch (char const *msg) {
		cerr << msg << endl;
	}
	return 0;
}
