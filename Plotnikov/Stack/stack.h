#include "stdlib.h"

struct stack_y { int par; stack_y* previos; };
//struct stack_t {   };

void push(int x, stack_y** y);

int pop(stack_y** y);

void clear(stack_y** y);

