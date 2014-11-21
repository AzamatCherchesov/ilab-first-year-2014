/*{
this is function for stack
some function get constant pointer to stack in order to
don't change it cosualy
}*/
#ifndef STACK_DOUBLE_H
#define STACK_DOUBLE_H

//define area
#define type_stack double
const int START_STK_SIZE = 10;
const int STK_SIZE_STEP = 5;

const int GOOD_STK = 0;
const int BAD_STK = 1;
const int OVERFULL_STK = 2;
const int BAD_STK_BUF = 3;
const int STK_UNSIZED = 4;
const int EMPTY_STACK = 5;

const int  ERR_STR_MAX_SIZE = 64;
const char ERR[][ERR_STR_MAX_SIZE]={
    "this is good stack",
    "this is bad stack",
    "this stack is overfull",
    "the place for our dates is so bad, that i can't write",
    "this stack hasn't size",
    "this stack is empty"
};

struct Stack {
  type_stack *buf;   //the place, where dates are kept
  int size;      //size of our buffer
  int count;     //current number elements of stak
};
typedef struct Stack stack;
/*{
  inicialize stack
  this function get start size of buffer
  and mark out place for it
}*/
stack* Stack_Ini();
/*{
  delete stack
  delete buffer and pointer to stack
}*/
stack Stack_Del (stack *st);
/*{
  return number elements of stack
}*/
int Stack_Get_Size(const stack *st);
/*{
  return error code if stack is't OK
  and '0' if it is good stack
}*/
int Is_Stack_Bad(const stack *st);
/*{
  print all possible informaton about stack
}*/
void Stack_Dump(const stack *st);
/*{
  usual assert with dump
}*/
void Stack_Assert (const stack *st);
/*{
  change size of stack buffer
}*/
void Stack_Realloc(stack* st);
/*{
  push elem in stack
}*/
void Push(stack *st, type_stack elem);
/*{
  give last value and delete it from stack
}*/
type_stack Pop(stack *st);
/*{
  give last value and don't delete it from stack
}*/
type_stack Pop_Without_DEl(stack *st);
/*{
  arithmetic operations with two latest numerals in stack
  *
  /
  +
  -
}*/
void mul(stack *st);
void div(stack *st);
void add(stack *st);
void sub(stack *st);


#endif // STACK_DOUBLE_H
