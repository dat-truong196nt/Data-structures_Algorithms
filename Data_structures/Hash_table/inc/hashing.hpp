#include <iostream>

using namespace std;

template <typename T>
class hashTable
{
private:
	pair<string, T> *table;
	int size;
	int _hash(const string &key);

public:
	hashTable(int size);
	void add(const string &key, const T &value);
	T get(const string &key);
};
