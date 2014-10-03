#include <stdio.h>
#include <math.h>

struct coeff
{
       double a,b,c;
};
//==============================================================================
struct root
{
       double x1,x2;
       char num;
};
//==============================================================================
double discr(coeff K)
{
       return K.b*K.b-4*K.a*K.c;
}
//==============================================================================
double ROOTS(coeff &K,double D,bool n)
{
       if(n)  return (-K.b+sqrt(D))/(2*K.a);
       if(!n) return (-K.b-sqrt(D))/(2*K.a);
}
//==============================================================================
void equation(coeff K, root &R)
{
       double D;
            if(K.a==0)                                                          //уровнение не квадратное
            {
                 R.x1=-K.c/K.b;
                 R.num=1;                             
            }
            else 
                if (K.b==0)
                {
                    if (K.c<=0)
                    {
                      R.x1=sqrt(K.c/K.a);                                       //корни отличаются 
                      R.x2=-R.x1;                                               //только знаком
                      R.num=2;
                    }
                    else
                       {
                              R.num=0;
                       }                                                    
                } 
                else
                    if (K.c==0)
                    {
                        R.x1=0;
                        R.x2=(-K.b/K.a);                                        //один корень ноль
                        R.num=2; 
                    }                                                           //, другой соответственно                    }
                    else
                    {
                      D = discr(K); 
                      if (D>0)                                                  //2 корня 
                      {                                  
                          R.x1 = ROOTS(K,D,0);
                          R.x2 = ROOTS(K,D,1);
                          R.num=2;   
                       }
                       else
                           if(D==0)
                              {
                                 R.x1=ROOTS(K,D,0);                             //один корень
                                 R.x2=R.x1;
                                 R.num=1;                                       
                              }       
                           else 
                              if(D<0) R.num=0;                                  //нет корней
                    }            
 }
//==============================================================================
main()
{    
      printf("ENTER \"0 0 0\"  TO EXIT\n");
      printf("PLEASE ENTER JUST NUMERALS\n"); 
      coeff  K;
      root   R;
      double x1=0,x2=0;
      char   num=0;
      K.a = 0;
      K.b = 0;
      K.c = 0;
      R.x1 = 0;
      R.x2 = 0;
      R.num = 0;
      do
      {
          scanf("%lg %lg %lg", &K.a, &K.b, &K.c);                                  //ввод       
          equation(K,R);
          switch(R.num)
            {
               case 2:printf("x1=%lg\nx2=%lg\n",R.x1,R.x2);break;
               case 1:printf("x=%lg\n",R.x1);break;
               case 0:printf("the equation haven't roots\n");break; 
               default: break;
            }
      }
      while((K.a!=0)||(K.b!=0)||(K.c!=0));

}
