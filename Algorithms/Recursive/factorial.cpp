#include <iostream>

using namespace std;

int findFactorialRecursive(const int& value) {
	if (value == 0 || value == 1) return 1;

	return value * findFactorialRecursive(value - 1);
}

int findFactorialIterative(const int& value) {
	int result = 1;

	for (int i = 1; i <= value; i++)
		result *= i;

	return result;
}

int main() {
	cout << findFactorialIterative(1) << endl;
	cout << findFactorialRecursive(5) << endl;
	return 0;
}