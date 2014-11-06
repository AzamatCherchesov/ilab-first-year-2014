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

const char ERR[][]={
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


#endif // STACK_DOUBLE_H
