/**
*   Stack (LIFO) data structure.
*
*   @file stack.h
*
*   @date 05.2015
*
*   @copyright GNU GPL v2.0
*
*   @author Viktor Prutyanov mailto:vitteran@gmail.com 
*/

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <vector>

using std::vector;

template <typename T>
class Stack
{
public:
    Stack(size_t size);
    ~Stack();
    void Push(T value);
    T Pop();
    bool Ok();
    bool Dump(FILE *dump_file);
    bool IsFull();
    bool IsEmpty();
    size_t GetSize();
    size_t GetCount();
private:
    size_t size;
    size_t count;
    vector<T> v_data;
};

template <typename T>
Stack<T>::Stack(size_t size) : count(0), v_data(vector<int>(size, 0))
{
	//Nothing to do
}

template <typename T>
Stack<T>::~Stack()
{
	v_data.~vector();
	count = 0;
}

template <typename T>
void Stack<T>::Push(T value)
{
	if (count == v_data.size())
	{
		v_data.push_back(value);
	}
	else
	{
		v_data.at(count) = value;
	}
	count++;
}

template <typename T>
T Stack<T>::Pop()
{
	if (count == 0)
	{
		throw std::out_of_range("Attemp to pop from empty stack. Nothing is done.");
		return 0;
	}
	T value = v_data.at(count - 1);
	count--;
	return value;
}

template <typename T>
bool Stack<T>::Ok()
{
	return !(count > v_data.size());
}

template <typename T>
bool Stack<T>::Dump(FILE *dump_file)
{
	if (Ok())
	{
		fprintf(dump_file, "Stack [0x%x] is OK. \n\tCount = %d Size = %d Capacity = %d\n", this, count, v_data.size(), v_data.capacity());
		for (size_t i = 0; i < count; i++)
		{
			fprintf(dump_file, "\t[%d] %d\n", i, v_data.at(i));
		}
		return true;
	}
	else
	{
		fprintf(dump_file, "Stack [0x%x] is NOT OK. \n\tCount = %d Size = %d Capacity = %d\n", this, count, v_data.size(), v_data.capacity());
		return false;
	}
}

template <typename T>
bool Stack<T>::IsFull()
{
	return (count == v_data.size());
}

template <typename T>
bool Stack<T>::IsEmpty()
{
	return (count == 0);
}

template <typename T>
size_t Stack<T>::GetCount()
{
	return count;
}

template <typename T>
size_t Stack<T>::GetSize()
{
	return v_data.size();
}
