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
		for (int i = 0; i < vect.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (vect.at(i) < vect.at(j)) {
					vect.insert(vect.begin() + j, vect.at(i));
					vect.erase(vect.begin() + i + 1);
				}
			}
		}
	};

	vector<int> vect = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
	sorting(vect);
	for (auto item: vect)
		cout << item << " ";
	return 0;
}