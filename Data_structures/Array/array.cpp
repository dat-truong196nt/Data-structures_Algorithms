#include "array.hpp"

template <typename T>
myArray<T>::myArray(int capacity = 2)
{
	this->arr = new T(capacity);
	this->size = 0;
	this->capacity = capacity;
}

template <typename T>
myArray<T>::~myArray()
{
	delete this->arr;
	this->size = 0;
}

template <typename T>
int myArray<T>::_autoExpand()
{
	if (size > 80*capacity/100) {
		T *tmpArr = new T(2 * size);
		for (int i = 0; i < this->size; i++)
			tmpArr[i] = this->arr[i];
		delete this->arr;
		this->arr = tmpArr;
	}
	return this->capacity;
}

template <typename T>
int myArray<T>::_autoShrink()
{
	if (size < 20*capacity/100) {
		T *tmpArr = new T(2 * size);
		for (int i = 0; i < this->size; i++)
			tmpArr[i] = this->arr[i];
		delete this->arr;
		this->arr = tmpArr;
	}
	return this->capacity;
}


template <typename T>
void myArray<T>::_shiftLeft(const int &index)
{
	for (int i = index; i < this->size - 1; i++)
		this->arr[i] = this->arr[i + 1];
	this->size--;
}

template <typename T>
void myArray<T>::_shiftRight(const int &index)
{
	for (int i = this->size - 2; i >= index; i--)
		this->arr[i + 1] = this->arr[i];
	this->size++;
}

template <typename T>
int myArray<T>::push(T item)
{
	_autoExpand();
	this->arr[this->size] = item;
	return ++this->size;
}

template <typename T>
T myArray<T>::pop()
{
	_autoShrink();
	T itemPop = this->arr[--this->size];
	return itemPop;
}

template <typename T>
T myArray<T>::del(const int &index)
{
	_autoShrink();
	if (index < this->size && index >= 0)
	{
		T item = this->arr[index];
		this->_shiftLeft(index);
		this->size--;
		return item;
	}
	return 0;
}

template <typename T>
T myArray<T>::insert(const T &item, const int &index)
{
	_autoExpand();
	if (index < this->size && index >= 0)
	{
		this->_shiftRight(index);
		this->arr[index] = item;
		this->size++;
		return item;
	}
	return 0;
}


template <typename T>
int myArray<T>::length()
{
	return this->size;
}

template <typename T>
T myArray<T>::get(int index)
{
	if (index < this->size && index >= 0)
		return this->arr[index];
	return 0;
}