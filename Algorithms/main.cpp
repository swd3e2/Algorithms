#include <iostream>
#include "search/BSTTree.h"
#include "search/SearchTree.h"
#include "search/AVLTree.h"
#include "search/RBTree.h"
#include "search/SkipList.h"
#include "search/HashMap.h"

struct Key
{
	int key;

	Key(int key) :
		key(key)
	{}

	bool operator<(const Key& other) const
	{
		return key < other.key;
	}
};

struct Item
{
	int val;
	Key k;

	Item(int val) :
		val(val), k(val)
	{}

	const Key& key() const
	{
		return k;
	}

	void show(std::ostream& os)
	{
		std::cout << val << std::endl;
	}
};

std::ostream& operator<<(std::ostream& os, const Item& item) { os << item.key().key << std::endl; return os; }

class MyString
{
private:
	char* data;
	mutable bool isValid;
public:
	MyString(const char* string) :
		isValid(true)
	{
		data = new char[strlen(string) + 1];
		memcpy(data, string, strlen(string) + 1);
	}

	char& operator[](const size_t position) 
	{
		return const_cast<char&>(static_cast<const MyString&>(*this)[position]);
	}

	const char& operator[](const size_t position) const
	{
		isValid = false;
		return data[position];
	}
};

int main(void)
{
	MyString string("musicked maximums");
	string[0] = '1';

	SkipList::SkipList<Item, Key> list;

	HashMap::HashMap<int, int> map;
	for (int i = 10; i < 100; i++)
		map.insert(i, i);

	map[10] = 12;

	std::cin.get();
}