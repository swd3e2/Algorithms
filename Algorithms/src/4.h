#pragma once
#include <iostream>

template <typename T>
class Stack {
private:
	T* data;
	int pointer = 0;
public:
	Stack(int size)
	{
		data = new T[size]{ 0 };
	}

	bool empty() { return pointer == 0; }
	void push(const T& item) { data[pointer++] = item; }
	T pop() {
		T val = data[--pointer];
		data[pointer] = 0;
		return val;
	}
};

void func()
{
	Stack<int> save(10);
	char* row = new char[100];
	char temp;
	std::cin >> row;

	for (int i = 0; i < strlen(row); i++) {
		temp = row[i];
		if (temp == '+') {
			save.push(save.pop() + save.pop());
		}

		if (temp == '*') {
			save.push(save.pop() * save.pop());
		}

		if (temp >= '0' && temp <= '9') {
			save.push(atoi(&temp));
		}
	}
}

void func2()
{
	Stack<char> save(10);
	Stack<char> oper(10);
	char* row = new char[100];
	char temp;
	std::cin >> row;

	for (int i = 0; i < strlen(row); i++) {
		temp = row[i];
		if (temp == ')') {
			save.push(oper.pop());
		}
		if (temp >= '0' && temp <= '9') {
			save.push(temp);
		}
		if (temp == '+' || temp == '*') {
			oper.push(temp);
		}
	}
}

template <typename T>
class fifo_array
{
private:
	T* data;
	int insertPointer = 0;
	int getPointer = 0;
	int size = 0;
public:
	fifo_array(int size) :
		size(size)
	{
		data = new T[size];
	}

	T& get()
	{
		return data[getPointer++ % size];
	}

	void put(const T& item)
	{
		data[insertPointer++ % size] = item;
	}
};