#include "stack_the_fox.h"
#include <stdio.h>
#include <stdlib.h>

Stack* stack_ctor ( void )
{
    Stack* st = ( Stack* ) calloc ( 1, sizeof(Stack) );
    st->size_st = size_of_stack;
    st->count_st = 0;
    st->data = ( int* ) calloc ( st->size_st, sizeof(int) );
    assert( stack_ok );
    return st;
}

int push ( Stack* st, int elem_st )
{
    assert( stack_ok );
    if (is_full_st(st)) return -1;
    st->data[ st->count_st] = elem_st;
    st->count_st ++;
    assert( stack_ok );
    return 0;
}

int is_empty_st ( Stack* st )
{
    assert( stack_ok );
    return st->count_st == 0;
}

int is_full_st ( Stack* st )
{
    assert( stack_ok );
    return st->count_st >= st->size_st;
}

int pop( Stack* st )
{
    assert( stack_ok );
    if (is_empty_st(st)) return -1;
    st->count_st--;
    return st->data[st->count_st ];
}


int stack_ok(const Stack* st)
{

    if ( ! st ) return -1;
    if ( ! st -> data ) return -1;
    return 0;
}
