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

class Stack
{
public:
    Stack(size_t size);
    ~Stack();
    bool Push(int value);
    bool Pop(int *value);
    bool Ok();
    bool Dump(FILE *file);
    bool IsFull();
    bool IsEmpty();
    size_t GetSize();
    size_t GetCount();
private:
    size_t size;
    size_t count;
    int *data;
};
