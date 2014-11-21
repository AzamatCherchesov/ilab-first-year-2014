#include "stdlib.h"

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
