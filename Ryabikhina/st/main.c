#include <stdio.h>
#include <stdlib.h>
#include "stack_the_fox.h"



int main()
{
    Stack* st = stack_ctor();
    push(st,10);
    push(st,20);
    printf("poped %d element\n", pop(st));
    printf("poped %d element\n", pop(st));
    printf("poped %d element\n", pop(st));

    return 0;

}
