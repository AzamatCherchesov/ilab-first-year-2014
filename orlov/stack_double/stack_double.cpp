#include "stack_double.h"

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

stack* Stack_Ini()
{
    stack *st;
    st->count = 0;
    st->size = START_STK_SIZE;
    st->buf = (type_stack *)calloc(st->size, sizeof(type_stack));
}

stack Stack_Del (stack *st)
{
    free(st->buf);
    st->count = -1;
    st->size = -1;
    free(st);
}

int Stack_Get_Size(const stack *st)
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
    printf("data [%lg] max = %i\n", st->buf, st->size);
    printf("\n");
    int i = 0;
    for (i = 0; i < st->count; i++)
      printf("[%i] = %lg <--\n", i, st->buf[i]);  //value in stack
    for (;i < st->size;i++)
      printf("[%i] = %lg !\n", i, st->buf[i]);    //value out of stack
    printf("}\n");
}

void Stack_Assert (const stack *st)
{
    if (Is_Stack_Bad(st))
    {
        Stack_Dump(st);
        assert(Is_Stack_Bad(st));
    }
}

void Stack_Realloc(stack* st)
{
    if (Is_Stack_Bad(st) != OVERFULL_STK)  Stack_Assert(st);
    st->size += STK_SIZE_STEP;
    st->buf = (type_stack *) realloc(st->buf, st->size * sizeof(type_stack));
    Stack_Assert(st);
}
void Push(stack *st, type_stack elem)
{
    if (!Is_Stack_Bad(st))
    {
        st->buf[st->count++] = elem;
    }
    else
        if (Is_Stack_Bad(st) == OVERFULL_STK)
        {
            Stack_Realloc(st);
            st->buf[st->count++] = elem;
        }
        else Stack_Assert(st);
}

type_stack Pop(stack *st)
{
    if (!Is_Stack_Bad(st))
    {
        return st->buf[--st->count];
    }
    else Stack_Assert(st);
    return Is_Stack_Bad(st);
}

type_stack Pop_Without_DEl(stack *st)
{
    if (!Is_Stack_Bad(st))
    {
        int i = st->count;
        return st->buf[--i];
    }
    else Stack_Assert(st);
    return Is_Stack_Bad(st);
}
