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

    st ->  size_st = sz;
    st -> count_st =  0;

    st -> data = ( int* ) calloc ( st->size_st, sizeof(int) );

    st -> err_code = S_OK;

    if ( st->data == NULL )
    {
        st -> err_code = S_ERR_NO_DATA;

        return NULL;
    }

    assert ( ok_st ( st ) == S_OK );

    st -> err_code = S_OK;

    return st;
}

int push_st ( Stack* st, int elem_st )
{
    // A little crutch. Program doesn't stop now if it is empty.
    if ( st -> err_code == S_ERR_EMPTY_STACK )
    {
        st -> err_code = S_OK;
    }

    assert ( ok_st ( st ) == S_OK );

    if ( is_full_st ( st ) )
    {
        if ( expand_st ( st ) != S_OK )
        {
            return S_ERR_EXPANSION;
        }
    }

    st -> data [ st -> count_st ] = elem_st;
    st -> count_st ++;

    assert ( ok_st ( st ) == S_OK );

    st -> err_code = S_OK;

    return S_OK;
}

int is_empty_st ( Stack* st )
{
    // A little crutch. Program doesn't stop now if it is empty.
    if ( st -> err_code == S_ERR_EMPTY_STACK )
    {
        st -> err_code = S_OK;
    }

    assert ( ok_st ( st ) == S_OK );

    st -> err_code = S_OK;

    return st -> count_st == 0;
}

int is_full_st ( Stack* st )
{
    // A little crutch. Program doesn't stop now if it is empty.
    if ( st -> err_code == S_ERR_EMPTY_STACK )
    {
        st -> err_code = S_OK;
    }

    assert ( ok_st ( st ) == S_OK );

    st -> err_code = S_OK;

    return st -> count_st >= st -> size_st;
}

int pop_st ( Stack* st )
{
    // A little crutch. Program doesn't stop now if it is empty.
    if ( st -> err_code == S_ERR_EMPTY_STACK )
    {
        st -> err_code = S_OK;
    }

    assert ( ok_st ( st ) == S_OK );

    if ( is_empty_st ( st ) ) // return S_ERR_EMPTY_STACK;
    {
        st -> err_code = S_ERR_EMPTY_STACK;

        return S_ERR_EMPTY_STACK;
    }

    st -> count_st --;

    st -> err_code = S_OK;

    return st -> data [ st -> count_st ];
}


int ok_st ( Stack* st )
{
    if ( st == NULL ) //return S_ERR_NO_STACK;
    {
        st -> err_code = S_ERR_NO_STACK;
    }

    else if ( st -> data == NULL ) //return S_ERR_NO_DATA;
    {
        st -> err_code = S_ERR_NO_DATA;
    }

    // I don't think that empty stack is an error
    /*
    if ( st -> err_code == S_ERR_EMPTY_STACK )
    {
        st -> err_code = S_OK;
    }
    */

    //if ( st -> err_code != S_OK ) return st -> err_code;

    return st -> err_code;

    //return S_OK;
}


Stack* stack_dtor ( Stack* st )
{
    free ( st -> data ); // Only for the first stack.
    free ( st         );

    st = NULL;

    return st;
}


int expand_st ( Stack* st )
{
    // A little crutch. Program doesn't stop now if it is empty.
    if ( st -> err_code == S_ERR_EMPTY_STACK )
    {
        st -> err_code = S_OK;
    }

    assert ( ok_st ( st ) == S_OK );

    st -> size_st ++;

    st -> data = ( int* ) realloc ( st -> data, ( st -> size_st ) * sizeof(int) );

    if ( !( st -> data ) ) //return S_ERR_EXPANSION;
    {
        st -> err_code = S_ERR_EXPANSION;

        return S_ERR_EXPANSION;
    }

    st -> err_code = S_OK;

    return S_OK;
}


int dump_st ( Stack* st )
{
    printf ( "--dump-st-- WE BEGIN OUR DUMP.\n" );

    int i = 0;

    for ( i = 0; i < st -> size_st; i++ )
    {
        printf ( "--dump-st-- data[%4d] = %10d\n", i, st -> data [ i ] );
    }

    printf ( "--dump-st-- Stack properties: size = %4d, counter = %4d\n\n\n",
             st -> size_st, st -> count_st );

    return S_OK;
}


int top_st ( Stack* st )
{
    // A little crutch. Program doesn't stop now if it is empty.
    if ( st -> err_code == S_ERR_EMPTY_STACK )
    {
        st -> err_code = S_OK;
    }

    assert ( ok_st ( st ) == S_OK );

    if ( is_empty_st ( st ) ) //return S_ERR_EMPTY_STACK;
    {
        st -> err_code = S_ERR_EMPTY_STACK;

        return S_ERR_EMPTY_STACK;
    }

    st -> err_code = S_OK;

    return st->data [ st->count_st ];
}
