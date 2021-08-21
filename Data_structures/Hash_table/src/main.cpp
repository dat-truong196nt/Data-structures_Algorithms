#include <iostream>
#include <hashing.hpp>

using namespace std;

int main()
{
	class hashTable<string> hash(1000);
	hash.add("My key", "My value");
	hash.add("My key1", "My value1");
	hash.add("My key2", "My value2");
	hash.add("My key3", "My value3");
	hash.add("My key4", "My value4");
	hash.add("My key5", "My value5");
	hash.add("My key6", "My value6");
	hash.add("My key7", "My value7");
	hash.add("My key8", "My value8");
	hash.add("My key9", "My value9");
	hash.add("My key10", "My value10");
	cout << hash.get("My key");
	return 0;
}