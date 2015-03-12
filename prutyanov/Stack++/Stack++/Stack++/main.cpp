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

#define test_Pop(x) std::cout << stack##x.Pop() << " popped.\n";
#define test_Push(x) stack##x.Push(rand());
#define test_Dump(x) stack##x.Dump(stdout);

#include "stack.h"
#include <iostream>

int main()
{
    Stack<int> stack1(3);
	test_Dump(1);
	test_Push(1);
	test_Push(1);
	test_Push(1);
	test_Dump(1);
	test_Push(1);
	test_Dump(1);
	test_Pop(1);
	test_Pop(1);
	test_Pop(1);
	test_Pop(1);
	test_Dump(1);
	std::cout << "Now we will try to pop from empty stack.\n";
	try
	{
		test_Pop(1);
	}
	catch (const std::out_of_range& e)
	{
		std::cout << e.what() << "\n";
	}
	test_Dump(1);


	Stack<bool> stack2(3);
	std::cout << "------------------------------------------------\n";
	test_Dump(2);
	stack2.Push(1);
	stack2.Push(0);
	stack2.Push(0);
	stack2.Push(1);
	stack2.Push(0);
	stack2.Push(0);
	stack2.Push(1);
	stack2.Push(1);
	test_Dump(2);
	stack2.Push(1);
	stack2.Push(0);
	stack2.Push(1);
	stack2.Push(1);
	stack2.Push(1);
	stack2.Push(0);
	test_Dump(2);

    #ifdef _DEBUG
        system ("pause");
    #endif

    return EXIT_SUCCESS;
}