/**
*   Stack (LIFO) data structure.
*
*   @file stack.cpp
*
*   @date 05.2015
*
*   @copyright GNU GPL v2.0
*
*   @author Viktor Prutyanov mailto:vitteran@gmail.com 
*/

#include "stack.h"
#include <ostream>

template <typename T>
Stack<T>::Stack(size_t size) : count (0), v_data (vector<int>(size, 0)) 
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