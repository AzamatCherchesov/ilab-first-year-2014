#ifndef STACK_THE_FOX_H_INCLUDED
#define STACK_THE_FOX_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//it's the state of the stack
const enum state
 {
    S_ERR_EXPANSION        = -3643343,
    S_ERR_EMPTY_STACK  = -2999912,
    S_ERR_NO_STACK         = -6456434,
    S_ERR_NO_DATA            = -9546656,
    S_OK                                  = 9876542,
    S_WRONG_COUNTER    = -3476473
};

//the structure of stack, which include parameters of a stack:
//size_st - the size
//data - a massive, which includes elements of a stack
//count st - is the next free location in a stack
typedef struct
{
    int size_st;
    int* data;
    int count_st;

} Stack;

//the creation of a stack
//takes: size of a new stack
Stack* stack_ctor ( int sz );

//function  pushes element in free location of a stack
//arguments : pointer to stack  and element, which should be pushed
//returns: the state of the stack
int push_st ( Stack* st, int elem_st );

//function popes the last element from a stack
//arguments : pointer to stack  and element, which should be poped
//returns: the state of the stack
int pop_st ( Stack* st );

// the function  returns the correct condition of a stack
//arguments : pointer to stack
int ok_st ( Stack* st );

//the function deletes a stack
//arguments : pointer to stack
Stack* stack_dtor ( Stack* st );

//the function checks if a stack is empty
//arguments : pointer to stack
int is_empty_st ( Stack* st );

//the function expands number of data elements
//arguments : pointer to stack
int expand_st ( Stack* st );

//the function  prints all information about the stack
//arguments : pointer to stack
int dump_st ( Stack* st );

//the function finds the top element of a stack
//arguments : pointer to stack
// returns: top element
int top_st ( Stack* st );

#endif // STACK_THE_FOX_H_INCLUDED
