#include "../inc/hashing.hpp"

template <typename T>
hashTable<T>::hashTable(int size)
{
	table = new pair<string, T>[size];
	this->size = size;
}

template <typename T>
int hashTable<T>::_hash(const string &key)
{
	int hash = 0;
	for (int i = 0; i < key.length(); i++) {
		hash = (hash + key[i] * i) % size;
	}
	return hash;
}

template <typename T>
void hashTable<T>::add(const string &key, const T &value)
{
	table[_hash(key)] = make_pair(key, value);
}

template <typename T>
T hashTable<T>::get(const string &key) {
	return table[_hash(key)].second;
}

template class hashTable<int>;
template class hashTable<float>;
template class hashTable<string>;