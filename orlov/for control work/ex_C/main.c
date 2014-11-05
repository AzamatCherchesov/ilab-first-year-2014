#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//========================================================================
int is_square(int num){
  if (sqrt(num) - (int )sqrt(num) == 0)  return 1;
    else return 0;
}

void ex_C(unsigned int n){

  int a = 0, b = 0, c = 0, d = 0;
  unsigned int sq = 0;
  for (a = 0; sq != n; a++)
      for (b = 0; sq != n; b++)
          for (c = 0; sq != n; c++)
              for (d = 0; sq != n; d++)
                  sq = a*a + b*b + c*c + d*d;
 a--;
 b--;
 c--;
 d--;
  printf ("%u %u %u %u",a*a, b*b, c*c, d*d);
}
//=======================================================================


int main()
{
  int n;
  scanf("%i",&n);
  ex_C(n);

 // system("PAUSE");
 return 0;
}
