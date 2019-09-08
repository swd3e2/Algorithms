#pragma once

namespace HashMap
{
	template<class T, class K>
	class HashMap
	{
	public:
		struct pair
		{
			K first;
			T second;

			pair(const K& key, const T& value) :
				first(key), second(value)
			{}
		};
	private:
		struct node
		{
			pair value;
			node* next;

			node(const pair& p, node* next) :
				value(p), next(next)
			{}
		};
	private:
		size_t capacity;
		node** map;
	private:
		const int hash(const T& value) const
		{
			return value & (capacity - 1);
		}
	public:
		HashMap() :
			capacity(16), map(new node*[capacity])
		{
			memset(map, 0, capacity);
		}

		void insert(const K& key, const T& value)
		{
			int hashed = hash(key);
			map[hashed] = new node(pair(key, value), map[hashed]);
		}

		T& operator[](const K& key)
		{
			int hashed = hash(key);
			node* temp = map[hashed];
			while (temp != nullptr && temp->value.first != key) {
				temp = temp->next;
			}

			return temp->value.second;
		}
	};
}