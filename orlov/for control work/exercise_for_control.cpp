#include <stdio.h>
#include <math.h>
#include <conio.h>


void ex_A(int n);                                // for first exercise 
void ex_B(int n);                                // for second exercise
void ex_C(unsigned int n);                       // for third exercise
void ex_D(int n, int k);


int is_square(int num);
unsigned int max_square(unsigned int num);

int main(){
 unsigned int n=0;
 
// scanf("%u",&n);
// ex_A(n);
// scanf("%u",&n);
// ex_B(n);
 scanf("%u",&n);
 ex_C(n);
 
    getch();
 return 0;   
}


//==============================================================================
void ex_A(int n){
  int i = 0, j = 0;                              //here a=j, k=i
  
  for (i = 0;i < n;i++){
    for (j = 1;j < n;j++){
      printf("%i ", ( (int )pow(j, i) ) % n );   //(a^k) mod N == (j^i)%N 
    }
    printf("\n");
  }
}
//==============================================================================
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

int is_square(int num){
  if (sqrt(num) - (int )sqrt(num) == 0)  return 1;//sqrt(n) - round(n) == 0
    else return 0;
}
//==============================================================================
unsigned int max_square(unsigned int num){
  int i=0;
  for (i = num;i > 0;i--)
    if (is_square(i))  return i;
  
}

void ex_C(unsigned int n){
  
  int a = 0, b = 0, c = 0,d = 2;                   
  int n1 = n;                                        //we need sefe first value n
 
  a = max_square(n1);
  n1 = n1 - a;
  
  while  (!is_square(d)){                            //d = 0 = 0^2
  
     b = max_square(n1);
     n1 = n1 - b;
     c = max_square(n1);
     n1 = n1 - c;
     d = n1;
  
     if (!is_square(d)){
       a = (int )(sqrt(a)-1) * (sqrt(a)-1);             // a=a-1
       n1 = n - a;
     }
     
  }

  printf ("%u %u %u %u",d, c, b, a);
}

//======================================================================
void ex_D(int n, int k){
  const int N = 91, K = 11;
  int c[N][K] = {};
  int i = 0, j = 0;
  
  for (i = 0;i < N;++){
   c[0][i]=1;
   if (i <= 9)  c[i][1] = 1;
     else c[i][1] = 0;
   c[i][0] = 0;
  }
  
}















