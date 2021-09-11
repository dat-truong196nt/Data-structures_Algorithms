#include <iostream>

using namespace std;

int findFibonacciRecursive(const int& value) {
	if (value == 0 || value == 1) return value;

	return findFibonacciRecursive(value - 1) + findFibonacciRecursive(value - 2);
}

int findFibonacciIterative(const int& value) {
	int prevValue = 0, currValue = 1;

	if (value == 0 || value == 1) return value;

	for (int i = 2; i < value; i++) {
		currValue += prevValue;
		prevValue = currValue - prevValue;
	}

	return prevValue + currValue;
}

int main() {
	cout << findFibonacciIterative(12) << endl;
	cout << findFibonacciRecursive(12) << endl;
	return 0;
}