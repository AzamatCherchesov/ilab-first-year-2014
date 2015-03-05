/**
*   Stack (LIFO) data structure. Stack test.
*
*   @file main.cpp
*
*   @date 05.2015
*
*   @copyright GNU GPL v2.0
*
*   @author Viktor Prutyanov mailto:vitteran@gmail.com 
*/

#include "stack.h"
#include <iostream>

int main()
{
    std::cout << "Test: Stack test started.\n";
    Stack stack (10);
    std::cout << "Test: Stack created. Size is " << stack.GetSize () << "\n";
    stack.Dump (stdout);
    stack.Push (1337);
    std::cout << "Test: 1337 has pushed.\n";
    stack.Dump (stdout);
    stack.Push (417);
    std::cout << "Test: 417 has pushed.\n";
    stack.Dump (stdout);
    int val = 0;
    stack.Pop (&val);
    std::cout << "Test: " << val << " has popped.\n";
    std::cout << "Test: Count is " << stack.GetCount () << " now.\n";
    stack.Dump (stdout);

    #ifdef _DEBUG
        system ("pause");
    #endif
}