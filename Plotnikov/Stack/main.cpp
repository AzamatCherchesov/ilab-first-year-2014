#include "stdio.h"
#include "stack.h"

int main()
{
	stack_y* stack_memory = (stack_y*)malloc(sizeof(stack_y));
	stack_memory->previos = NULL;
	//stack_memory->par = 0;
	for (int i = 8; i <= 100; i+=7)
		push(i, &stack_memory);
	for (int i = 0; i <= 10; i++)
		printf("%d\n", pop(&stack_memory));
	push(10, &stack_memory);
	clear(&stack_memory);
	return 0;
}