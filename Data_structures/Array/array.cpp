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
	free(this->arr);
	this->size = 0;
}

template <typename T>
void myArray<T>::_shiftLeft(const int &index)
{
	for (int i = index; i < this->size - 1; i++)
		this->arr[i] = this->arr[i + 1];
	this->arr = (T *)realloc(this->arr, --this->size);
}

template <typename T>
void myArray<T>::_shiftRight(const int &index)
{
	this->arr = (T *)realloc(this->arr, ++this->size);
	for (int i = this->size - 2; i >= index; i--)
		this->arr[i + 1] = this->arr[i];
}

template <typename T>
int myArray<T>::push(T item)
{
	this->arr = (T *)realloc(this->arr, ++this->size);
	this->arr[this->size - 1] = item;
	return this->size - 1;
}

template <typename T>
T myArray<T>::pop()
{
	T itemPop = this->arr[this->size - 1];
	this->arr = (T *)realloc(this->arr, --this->size);
	return itemPop;
}

template <typename T>
T myArray<T>::del(const int &index)
{
	if (index < this->size && index >= 0)
	{
		T item = this->arr[index];
		this->_shiftLeft(index);
		this->arr = (T *)realloc(this->arr, --this->size);
		return item;
	}
	return 0;
}

template <typename T>
T myArray<T>::insert(const T &item, const int &index)
{
	if (index < this->size && index >= 0)
	{
		this->_shiftRight(index);
		this->arr[index] = item;
		return item;
	}
	return 0;
}


template <typename T>
int myArray<T>::getLength()
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