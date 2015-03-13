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

//TODO: Add comments.

#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <iostream>
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
    bool Dump(std::ostream *dump_stream);
    bool IsFull();
    bool IsEmpty();
    size_t GetSize();
    size_t GetCount();
private:
    size_t count;
	vector<T> v_data;
};

template <>
class Stack<bool>
{
public:
	Stack(size_t size);
	~Stack();
	void Push(bool value);
	bool Pop();
	bool Ok();
	bool Dump(std::ostream *dump_stream);
	bool IsFull();
	bool IsEmpty();
	size_t GetSize();
	size_t GetCount();
private:
	size_t count;
	vector<unsigned char> v_data;
};

template <typename T>
Stack<T>::Stack(size_t size) 
	: count (0), v_data (vector<T>(size, 0))
{
	//Nothing to do
}

Stack<bool>::Stack(size_t size) 
	: count (0), v_data (vector<unsigned char>((size % 8 == 0) ? size : size / 8 + 1, 0))
{
	//Nothing to do
}

template <typename T>
Stack<T>::~Stack()
{
	v_data.~vector();
	count = 0;
}

Stack<bool>::~Stack()
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

void Stack<bool>::Push(bool bit_value)
{
	if (count == v_data.size() * 8)
	{
		v_data.push_back((bit_value ? 1 : 0) << 7);
	}
	else if (count != v_data.size() * 8 && count % 8 == 0)
	{
		v_data.at(count / 8) = (bit_value ? 1 : 0) << 7;
	}
	else
	{
		v_data.at(count / 8) |= (bit_value ? 1 : 0) << (7 - count % 8);
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
	return v_data.at(--count);
}

bool Stack<bool>::Pop()
{
	if (count == 0)
	{
		throw std::out_of_range("Attemp to pop from empty stack. Nothing is done.");
		return 0;
	}
	else
	{
		bool value = (v_data.at(count / 8 - (count % 8 == 0 ? 1 : 0)) >> (count % 8 == 0 ? 1 : 8 - count % 8)) & 1;
		count--;
		return value;
	}
}


template <typename T>
bool Stack<T>::Ok()
{
	return !(count > v_data.size());
}

bool Stack<bool>::Ok()
{
	return !(count > v_data.size() * 8);
}

template <typename T>
bool Stack<T>::Dump(std::ostream *dump_stream)
{
	if (Ok())
	{
		*dump_stream << "Stack is OK. \n\tCount = " << count << " Size = " << v_data.size() << " Capacity = " << v_data.capacity() << "\n";
		for (size_t i = 0; i < count; i++)
		{
			*dump_stream << "\t[" << i << "] " << v_data.at(i) << "\n";
		}
		return true;
	}
	else
	{
		*dump_stream << "Stack is CORRUPTED. \n\tCount = " << count << " Size = " << v_data.size() << " Capacity = " << v_data.capacity() <<  "\n";
		return false;
	}
}

bool Stack<bool>::Dump(std::ostream *dump_stream)
{
	if (Ok())
	{
		*dump_stream << "Stack is OK. \n\tCount = " << count << " Size = " << v_data.size() << " Capacity = " << v_data.capacity() << "\n";
		for (size_t i = 0; i < count / 8 + ((count % 8 == 0) ? 0 : 1) ; i++)
		{
			*dump_stream << "\t[" << i * 8 << "-" << i*8 + 7 << "] ";
			for (size_t j = 0; j < 8; j++)
			{
				if ((j >= count % 8) && (i == count / 8))
				{
					*dump_stream << "_";
				}
				else
				{
					*dump_stream << ((v_data.at(i) >> (7 - j)) & 1);
				}
			}
			*dump_stream << "\n";
		}
		return true;
	}
	else
	{
		*dump_stream << "Stack is CORRUPTED. \n\tCount = " << count << " Size = " << v_data.size() << " Capacity = " << v_data.capacity() << "\n";
		return false;
	}
}

template <typename T>
bool Stack<T>::IsFull()
{
	return (count == v_data.size());
}

bool Stack<bool>::IsFull()
{
	return (count == v_data.size());
}


template <typename T>
bool Stack<T>::IsEmpty()
{
	return (count == 0);
}

bool Stack<bool>::IsEmpty()
{
	return (count == 0);
}

template <typename T>
size_t Stack<T>::GetCount()
{
	return count;
}

size_t Stack<bool>::GetCount()
{
	return count;
}

template <typename T>
size_t Stack<T>::GetSize()
{
	return v_data.size();
}

size_t Stack<bool>::GetSize()
{
	return v_data.size();
}