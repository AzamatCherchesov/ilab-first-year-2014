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
#include <vector>
#include <ostream>

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
