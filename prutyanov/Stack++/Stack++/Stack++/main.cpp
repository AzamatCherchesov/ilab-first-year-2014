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

//TODO: Add comments.

#define test_Pop(x) std::cout << stack##x.Pop() << " popped.\n";
#define test_Push(x) stack##x.Push(rand());
#define test_Dump(x) stack##x.Dump(&std::cout);

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

	Stack<int> stack1_copy(stack1);
	std::cout << "Stack1 has copied. Copy dump: ";
	stack1_copy.Dump(&std::cout);

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
	test_Dump(2);
	stack2.Push(1);
	stack2.Push(1);
	stack2.Push(0);
	stack2.Push(1);
	test_Dump(2);
	stack2.Push(0);
	stack2.Push(1);
	stack2.Push(0);
	stack2.Push(1);
	stack2.Push(0);
	stack2.Push(1);
	stack2.Push(1);
	stack2.Push(1);
	test_Dump(2);
	stack2.Push(1);
	stack2.Push(0);
	test_Dump(2);

	Stack<bool> stack2_copy(stack2);
	std::cout << "Stack2 has copied. Copy dump: ";
	stack2_copy.Dump(&std::cout);

	test_Pop(2);
	test_Pop(2);
	test_Pop(2);
	test_Dump(2);

	for (size_t i = 0; i < 15; i++)
	{
		test_Pop(2);
	}
	test_Dump(2);

	std::cout << "Now we will try to pop from empty stack.\n";
	try
	{
		test_Pop(2);
	}
	catch (const std::out_of_range& e)
	{
		std::cout << e.what() << "\n";
	}

    #ifdef _DEBUG
        system ("pause");
    #endif

    return EXIT_SUCCESS;
}