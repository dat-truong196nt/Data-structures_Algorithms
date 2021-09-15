#include <iostream>
#include <vector>

using namespace std;

vector<int> naiveMerge(vector<int> left, vector<int> right) {
	vector<int> mergedArr;

	for (int i = 0; i < left.size(); i++) {
		for (int j = 0; j < right.size(); j++) {
			if (left.at(i) < right.at(j)) {
				mergedArr.push_back(left.at(i));
				left.erase(left.begin() + i);
				j--;
			} else {
				mergedArr.push_back(right.at(j));
				right.erase(right.begin() + j--);
			}
			if (left.empty())
				break;
		}
	}
	if (!left.empty()) {
		for (auto item: left)
			mergedArr.push_back(item);
	}
	else if (!right.empty()) {
		for (auto item: right)
			mergedArr.push_back(item);
	}
	return mergedArr;
}

vector<int> merge(vector<int> left, vector<int> right) {
	vector<int> mergedArr;
	int indexLeft = 0, indexRight = 0;

	while (indexLeft < left.size() && indexRight < right.size()) {
		if (left.at(indexLeft) < right.at(indexRight))
			mergedArr.push_back(left.at(indexLeft++));
		else
			mergedArr.push_back(right.at(indexRight++));
	}

	mergedArr.insert(mergedArr.end(), left.begin() + indexLeft, left.end());
	mergedArr.insert(mergedArr.end(), right.begin() + indexRight, right.end());

	return mergedArr;
}

vector<int> mergeSort (vector<int> array) {
  if (array.size() == 1) {
    return array;
  }
  // Split Array in into right and left
  vector<int> left = vector<int>(array.begin(), array.begin() + array.size()/2);
  vector<int> right = vector<int>(array.begin() + array.size()/2, array.end());

  return merge(
    mergeSort(left),
    mergeSort(right)
  );
}

int main () {
	vector<int> array = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 9, 5};

	vector<int> answer = mergeSort(array);
	for (auto item: answer)
		cout << item << " ";
	cout << endl;
}