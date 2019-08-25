#pragma once

template<typename T>
class HeapQueue
{
private:
	T* data;
	int* pk;
	int size;
	int currentSize;
private:
	void fixUp()
	{

	}

	void fixDown()
	{

	}
public:
	HeadpQueue(const int size) noexcept
	{
		data = new T[size];
		pk = new int[size];
		currentSize = 0;
		this->size = size;
	}

	void insert(const T& item)
	{
		data[currentSize++] = item;

	}

	const bool empty() const
	{
		return currentSize == 0;
	}

	const T getMax()
	{

	}
};