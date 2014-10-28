#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void ex_B(int n);


int main()
{
  int n;
  scanf("%i",&n);  
  
  ex_B(n);
  system("PAUSE");
 return 0;   
}


void ex_B(int n){
  const int N = 100;
  int i = 0, curr = 0, count = 0;
  int square[N] = {};
   
   for (i = 0;i < n;i++){
     scanf("%i",&curr);
  
     if (is_square(curr)){
       square[count] = curr;
       count++;
     }
   }
   for (i = 0;i < count;i++)  printf("%i ",square[i]);
   printf("\n");
}
//-----------------------------------------------------------------------
int is_square(int num){
  if (sqrt(num) - (int )sqrt(num) == 0)  return 1;
    else return 0;
}
