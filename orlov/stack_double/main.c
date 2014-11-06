/*
this is function for stack
*/

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

//define area
#define START_STK_SIZE 10
#define STK_SIZE_STEP 5

#define GOOD_STK 0
#define BAD_STK 1
#define OVERFULL_STK 2

struct Stack {
  double *buf;   //the place, where dates are kept
  int size;      //size of our buffer
  int count;     //current number elements of stak
};
typedef struct Stack stack;


int main()
{

  return 0;
}

int main(void)
{
    printf("Hello World!\n");
    return 0;
}

