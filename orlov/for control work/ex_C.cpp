#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//========================================================================
int is_square(int num){
  if (sqrt(num) - (int )sqrt(num) == 0)  return 1;
    else return 0;
}
//------------------------------------------------------------------------
unsigned int max_square(unsigned int num){
  int i=0;
  for (i = num; i > 0; i--)
    if (is_square(i))  return i;
  return NAN;
}
//-----------------------------------------------------------------------
/*{
In thi function we, firstly, find max number, which square
isn't more then n
After that we cut down n on this number and repeat this procedure three times
then if last number d isn't square any number we lessen a on 1 and repeat all 
procedure
It work and this programm work normaly on my computer
}*/
void ex_C(unsigned int n){
  
  int a = 0, b = 0, c = 0,d = 2;                   
  int n1 = n;
 
  a = max_square(n1);     
  n1 = n1 - a;
  
  while  (!is_square(d)){
  
     b = max_square(n1);
     n1 = n1 - b;
     c = max_square(n1);
     n1 = n1 - c;
     d = n1;
  
     if (!is_square(d)){
       a = (int )(sqrt(a)-1) * (int )(sqrt(a)-1);
       n1 = n - a;
     }
     
  }

  printf ("%u %u %u %u",d, c, b, a);
}
//=======================================================================


int main()
{
  int n;
  scanf("%i",&n);  
  ex_C(n);
  
  system("PAUSE");
 return 0;   
}
