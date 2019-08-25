#pragma once
#include <memory>

size_t getSize(const char* string)
{
	size_t size = 0;
	for (size = 0; string[size] != '\0'; ++size);
	return size;
}

class String
{
private:
	size_t capacity;
	union {
		struct no_small_buffer_t {
			char*  data;
			size_t size;
		} no_small_buffer;
		struct small_buffer_t {
			char data[sizeof(no_small_buffer_t)];
		} small_buffer;
	} impl;
public:
	String() = default;

	String(const char* string) 
	{
		capacity = getSize(string);
		if (capacity <= 8) {
			memcpy(impl.small_buffer.data, string, capacity);
		} else {
			impl.no_small_buffer.data = (char*)malloc(sizeof(char) * capacity);
			memcpy(impl.no_small_buffer.data, string, capacity);
			impl.no_small_buffer.size = capacity;
		}
	}

	String(const String& other) 
	{
		
	}

	String(String&& other)
	{
		if (other.capacity) {

		}
	}

	~String()
	{
		if (impl.no_small_buffer.data != nullptr) {
			free(impl.no_small_buffer.data);
		}
	}

	char operator[](int index)
	{

	}
};