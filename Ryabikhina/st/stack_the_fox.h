#ifndef STACK_THE_FOX_H_INCLUDED
#define STACK_THE_FOX_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define size_of_stack 4

//the structure of stack, which include parameters of a stack:
//size_st - the size
//data - a massive, which includes element of a stack
//count st - is the next free location in a stack
typedef struct
{
    int size_st;
    int* data;
    int count_st;
} Stack;

//the function of creation of a stack
Stack* stack_ctor(void);

//function which pushes element in free location of a stack
int push ( Stack* st,int elem_st );

//function which popes the last element from a stack
int pop ( Stack* st );

//returns the correct condition of a stack
int stack_ok(const Stack* st);

//the function deletes a stack
Stack* stack_dtor(void);

//checks if a stack is full
int is_full_st (Stack* st);

//checks if a stack is empty
int is_empty_st (Stack* st);

#endif // STACK_THE_FOX_H_INCLUDED
