/*{
this is function for stack
some function get constant pointer to stack in order to
don't change it cosualy
}*/
#ifndef STACK_DOUBLE_H
#define STACK_DOUBLE_H

//define area
#define START_STK_SIZE 10
#define STK_SIZE_STEP 5

#define GOOD_STK 0
#define BAD_STK 1
#define OVERFULL_STK 2
#define BAD_STK_BUF 3
#define STK_UNSIZED 4
#define EMPTY_STACK 5

const int ERR_STR_MAX_SIZE = 64;
const char ERR[][ERR_STR_MAX_SIZE]={
    "this is good stack",
    "this is bad stack",
    "this stack is overfull",
    "the place for our dates is so bad, that i can't write",
    "this stack hasn't size",
    "this stack is empty"
};

struct Stack {
  double *buf;   //the place, where dates are kept
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
void Push(stack *st, double elem);
/*{
  give last value and delete it from stack
}*/
double Pop(stack *st);
/*{
  give last value and don't delete it from stack
}*/
double Pop_Without_DEl(stack *st);



#endif // STACK_DOUBLE_H
