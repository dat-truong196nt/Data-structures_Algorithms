#include <iostream>
#include <vector>

using namespace std;

int main() {
	auto swap = [] (int &a, int &b) {
		a = a + b;
		b = a - b;
		a = a - b;
	};

	auto sorting = [&swap] (vector<int> &vect) {
		for (int i = vect.size() - 1; i >= 0; i--) {
			for (int j = 0; j < i; j++) {
				if (vect.at(j) > vect.at(j + 1)) swap(vect.at(j), vect.at(j + 1));
			}
		}
	};

	vector<int> vect = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
	sorting(vect);
	for (auto item: vect)
		cout << item << " ";
	return 0;
}