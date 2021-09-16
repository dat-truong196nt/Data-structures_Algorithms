#include <iostream>
#include <vector>

using namespace std;

pair<vector<int>, vector<int>> split(vector<int> arr) {
	int splitValue = *arr.rbegin();
	vector<int> left, right;

	for (int i = 0; i < arr.size() - 1; i++) {
		if (arr.at(i) < splitValue) left.push_back(arr.at(i));
		else right.push_back(arr.at(i));
	}
	return make_pair(left, right);
}

vector<int> quickSort (vector<int> arr) {
	if (arr.size() == 1 || arr.size() == 0) {
		return arr;
	}
	pair<vector<int> , vector<int>> part = split(arr);
	vector<int> leftPart = quickSort(part.first);
	vector<int> rightPart = quickSort(part.second);
	vector<int> result;
	result.insert(result.end(), leftPart.begin(), leftPart.end());
	result.push_back(*arr.rbegin());
	result.insert(result.end(), rightPart.begin(), rightPart.end());

	return result;
}

int main () {
	vector<int> arr = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 9, 5, 9};

	vector<int> answer = quickSort(arr);
	for (auto item: answer)
		cout << item << " ";
	cout << endl;
}