#include <iostream>
#include <array.hpp>

#define SUCCESS 0
#define FAIL -1

template <typename T>
void testPushing(class myArray<T> &arr, T input)
{
	arr.push(input);
	if (arr.get(arr.length() - 1) != input)
		throw "Failed to push (" + to_string(input) + ") into array";
}

template <typename T>
void testPop(class myArray<T> &arr)
{
	int preLen = arr.length();
	T lastValue = arr.get(arr.length() - 1);
	arr.pop();
	if (arr.length() != preLen - 1)
		throw "Failed to pop last item (" + to_string(lastValue) + ") out off array";
}

int	main()
{
	class myArray<int> arr;
	try {
		testPushing(arr, 20);
		testPop(arr);
		arr.print();
	} catch (const char *ex) {
		cout << ex << endl;
	}
	return 0;
}