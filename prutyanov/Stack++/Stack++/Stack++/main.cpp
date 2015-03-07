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
    Stack<int> stack (3);
    stack.Dump(stdout);
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
	stack.Dump(stdout);
    stack.Push(4);
	stack.Dump(stdout);
	std::cout << stack.Pop() << "\n";

    #ifdef _DEBUG
        system ("pause");
    #endif

    return EXIT_SUCCESS;
}