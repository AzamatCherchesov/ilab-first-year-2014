#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int const N = 100;

void ex_A(int n);

int main()
{
  int n;
  scanf("%i",&n);  
  
  ex_A(n);
  system("PAUSE");
 return 0;   
}
/*{
I don't know how describe this function
}*/
void ex_A(int n){
  int i = 0, j = 0;
  int a = 0, b = 1;
  int arr[N][N]={};
  
  for (i = 0; i < n; i++)
    for (j = 1; j < n; j++)
       arr[i][j]=1;
  
  for (i = 1; i < n; i++)
  {
    a = i % n;
    for 
    (j = 1;j < n;j++)
    {
      b = (b * a) % n;
      arr[j][i] = b;
    }
  }
  
  for (i = 0; i < n; i++)
  {
    for (j = 1; j < n; j++)
      printf("%i ",arr[i][j]);
    printf("\n");    
  }
}
