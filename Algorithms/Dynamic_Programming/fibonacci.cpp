#include <iostream>
#include <map>

using namespace std;

int cnt = 0, cntDP = 0;

int findFibonacciRecursive(const int& value) {
	cnt++;
	if (value == 0 || value == 1) return value;

	return findFibonacciRecursive(value - 1) + findFibonacciRecursive(value - 2);
}

int findFibonacciRecursiveDP(const int& value) {
	cntDP++;
	static map<int, int> cache;

	if (value == 0 || value == 1) return value;

	if (!cache[value])
		cache[value] = findFibonacciRecursiveDP(value - 1) + findFibonacciRecursiveDP(value - 2);

	return cache[value];
}

int main() {
	int targetFibo = 30;
	cout << findFibonacciRecursive(targetFibo) << " vs " << findFibonacciRecursiveDP(targetFibo) << endl;
	cout << cnt << " vs " << cntDP << endl;
	return 0;
}