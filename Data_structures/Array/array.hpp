
template <typename T>
class myArray
{
private:
	int size, capacity;
	T *arr;
	void _autoSrink();
	void _shiftLeft(const int &index);
	void _shiftRight(const int &index);

public:
	myArray(int capacity = 2);
	~myArray();
	int push(T item);
	T pop();
	T del(const int &index);
	T get(int index);
	T insert(const T &item, const int &index);
	int getLength();
};
