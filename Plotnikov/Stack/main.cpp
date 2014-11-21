#include "stdio.h"
#include "malloc.h"

struct stack_y { int par; stack_y* previos; };


void push(int x, stack_y** y)
{
	stack_y* stack_new = (stack_y*)malloc(sizeof(stack_y));
	stack_new->previos = *y;
	stack_new->par = x;
	*y = stack_new;
}

int pop(stack_y** y)
{
	int cash = (*y)->par;
	if ((*y)->previos == NULL) { *y = 0; return cash; }
	stack_y* stack_cash = (*y)->previos;
	free(*y);
	*y = stack_cash;
	return cash;
}

void clear(stack_y** y)
{
	stack_y* stack_cash;
	while ((*y) != NULL)
	{
		stack_cash = (*y)->previos;
		free(*y);
		*y = stack_cash;
	}
	*y = 0;
}

int main()
{
	stack_y* stack_memory = (stack_y*)malloc(sizeof(stack_y));
	stack_memory->previos = NULL;
	stack_memory->par = 0;
	for (int i = 8; i <= 100; i+=7)
		push(i, &stack_memory);
	for (int i = 0; i <= 10; i++)
		printf("%d\n", pop(&stack_memory));
	push(10, &stack_memory);
	clear(&stack_memory);
	return 0;
}