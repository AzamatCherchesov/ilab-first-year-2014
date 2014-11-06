#include "stack_double.h"
/*
this is function for stack
*/

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

/*{
  inicialize stack
}*/
stack* Stack_Ini()
{
    stack *st;
    st->count = 0;
    st->size = START_STK_SIZE;
    st->buf = (double *)calloc(st->size, sizeof(double));
}
/*{
  delete stack
}*/

stack Stack_Del (stack *st)
{
    free(st->buf);
    st->count = -1;
    st->size = -1;
    free(st);
}

int Stack_Get_Size(const satck *st)
{
    return st->count;
}

int Is_Stack_Bad(const stack *st)
{
    if (!st)                   return BAD_STK;
    if (st->size<=0)           return STK_UNSIZED;
    if (st->count >= st->size) return OVERFULL_STK;
    if (!st->buf)              return BAD_STK_BUF;
    return GOOD_STK;
}

void Stack_Dump(const stack *st)
{
    printf("st [%i],  %s\n", st,ERR[Is_Stack_Bad(st)]);
printf("{\n");
printf("count = %i\n", st->count);
printf("data [%i] max = %i\n", st->buf, st->size);
printf("\n");
for (int i = 0; i < st->size; i++)
printf("[%i] = %f\n", i, st->buf[i]);
printf("}\n");
}

void Stack_Assert (int err_code)
{
    if (err_code)
    {
        Stack_Dump(st);
        assert(("sorry but this stack isn't deserving your attantion ",err_code));
    }
}

void Stack_Realloc(stack* st)
{
    if (Is_Stack_Bad(st) != OVERFULL_STK)  Stack_Assert(Is_Stack_Bad(st));
    st->size += STK_SIZE_STEP;
    st->buf = (double *) realloc(st->buf, st->size * sizeof(double));
    Stack_Assert(Is_Stack_Bad(st));
}
void Push(stack *st, double elem)
{
    if (!Is_Stack_Bad(st))
    {
        st->buf[st->count++] = elem;
    }
    else Stack_Assert(Is_Stack_Bad(st));
}

double Pop(stack *st)
{
    if (!Is_Stack_Bad(st))
    {
        return st->buf[--st->count];
    }
    else Stack_Assert(Is_Stack_Bad(st));
    return Is_Stack_BAd(st);
}
