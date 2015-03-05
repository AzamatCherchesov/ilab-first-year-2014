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

Stack::Stack(size_t size) : size (size), data (new int[size]), count (0) 
{
    memset (data, 0, size);
}

Stack::~Stack()
{
    delete[] data;
    data = nullptr;
    count = -1;
    size = -1;
}

bool Stack::Push(int value)
{
    if (!Ok ()) return false;
    if (IsFull ()) 
    {
        data = (int *)realloc ((void *)(data), (size + 1) * sizeof (int));
        if (!Ok ()) return false;
        if (size != SIZE_MAX)
        {
            size++;
        }
        else
        {
            return false;
        }
    }
    (data)[count] = value;
    if (count != SIZE_MAX)
    {
        count++;
    }
    else
    {
        return false;
    }
    return Ok ();
}

bool Stack::Pop(int *value)
{
    if (Ok () && !IsEmpty ())
    {
        count--;
        *value = data[count];
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::Ok()
{
    return !((count < 0) || (size < 0) || (count > size) || (data == nullptr));
}

bool Stack::Dump(FILE *file)
{
    if (Ok ())
    {
        fprintf (file, "Stack [0x%x] is OK. \n\tcount = %d\n\tsize = %d\n\tdata [0x%x]:\n", this, count, size, data);
        for (int i = 0; i < count; i++)
        {
            printf("\t[%d] %d\n", i, *(data + i));
        }
        return true;
    }
    else
    {
        fprintf (file, "Stack [0x%x] is NOT OK. \n\tcount = %d\n\tsize = %d\n\tdata [0x%x]:\n", this, count, size, data);
        return false;
    }
}

bool Stack::IsFull()
{
    return (count == size);
}

bool Stack::IsEmpty()
{
    return (count == 0);
}

size_t Stack::GetCount()
{
    return count;
}

size_t Stack::GetSize()
{
    return size;
}