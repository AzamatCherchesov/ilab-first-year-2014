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

#define test_Pop std::cout << stack.Pop() << " popped.\n";
#define test_Push stack.Push(rand());
#define test_Dump stack.Dump(stdout);

#include "stack.h"
#include <iostream>

int main()
{
    Stack<int> stack (3);
	test_Dump;
	test_Push;
	test_Push;
	test_Push;
	test_Dump;
	test_Push;
	test_Dump;
	test_Pop;
	test_Pop;
	test_Pop;
	test_Pop;
	test_Dump;
	std::cout << "Now we will try to pop from empty stack.\n";
	try
	{
		test_Pop;
	}
	catch (const std::out_of_range& e)
	{
		std::cout << e.what() << "\n";
	}
	test_Dump;

    #ifdef _DEBUG
        system ("pause");
    #endif

    return EXIT_SUCCESS;
}