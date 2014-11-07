#ifndef STACK_THE_FOX_H_INCLUDED
#define STACK_THE_FOX_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#define S_ERR_EXPANSION   -3643343
#define S_ERR_EMPTY_STACK -2999912
#define S_ERR_NO_STACK    -6456434
#define S_ERR_NO_DATA     -9546656

#define S_OK 987654321



//the structure of stack, which include parameters of a stack:
//size_st - the size
//data - a massive, which includes elements of a stack
//count st - is the next free location in a stack
typedef struct
{
    int size_st;
    int* data;
    int count_st;

    int err_code;
} Stack;

//the function of creation of a stack
Stack* stack_ctor ( int sz );

//function which pushes element in free location of a stack
int push_st ( Stack* st, int elem_st );

//function which popes the last element from a stack
int pop_st ( Stack* st );

//returns the correct condition of a stack
int ok_st ( Stack* st );

//the function deletes a stack
Stack* stack_dtor ( Stack* st );

//checks if a stack is full
int is_full_st ( Stack* st );

//checks if a stack is empty
int is_empty_st ( Stack* st );

//expands number of data elements
int expand_st ( Stack* st );

//dump
int dump_st ( Stack* st );

// returns top element
int top_st ( Stack* st );

#endif // STACK_THE_FOX_H_INCLUDED
