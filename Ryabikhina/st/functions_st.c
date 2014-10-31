#include "stack_the_fox.h"
#include <stdio.h>
#include <stdlib.h>


Stack* stack_ctor ( int sz )
{
    Stack* st = ( Stack* ) calloc ( 1, sizeof(Stack) );

    if ( st == NULL )
    {
        return NULL;
    }

    st->size_st = sz;
    st->count_st = 0;
    st->data = ( int* ) calloc ( st->size_st, sizeof(int) );

    if ( st->data == NULL )
    {
        return NULL;
    }

    assert ( stack_ok ( st ) != ERR_NO_DATA &&
             stack_ok ( st ) != ERR_NO_STACK );

    return st;
}

int push ( Stack* st, int elem_st )
{
    assert ( stack_ok ( st ) != ERR_NO_DATA &&
             stack_ok ( st ) != ERR_NO_STACK );

    if ( is_full_st ( st ) ) return ERR_FULL_STACK;

    st->data [ st->count_st ] = elem_st;
    st->count_st ++;

    assert ( stack_ok ( st ) != ERR_NO_DATA &&
             stack_ok ( st ) != ERR_NO_STACK );

    return 0;
}

int is_empty_st ( Stack* st )
{
    assert ( stack_ok ( st ) != ERR_NO_DATA &&
             stack_ok ( st ) != ERR_NO_STACK );

    return st->count_st == 0;
}

int is_full_st ( Stack* st )
{
    assert ( stack_ok ( st ) != ERR_NO_DATA &&
             stack_ok ( st ) != ERR_NO_STACK );

    return st->count_st >= st->size_st;
}

int pop ( Stack* st )
{
    assert ( stack_ok ( st ) != ERR_NO_DATA &&
             stack_ok ( st ) != ERR_NO_STACK );

    if ( is_empty_st ( st ) ) return ERR_EMPTY_STACK;

    st->count_st--;

    return st->data[st->count_st ];
}


int stack_ok ( const Stack* st )
{
    if ( st == NULL ) return ERR_NO_STACK;

    if ( st -> data == NULL ) return ERR_NO_DATA;

    return 1;
}


Stack* stack_dtor ( Stack* st )
{
    free ( st );

    st = NULL;

    return st;
}
