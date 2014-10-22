#include <stdio.h>
#include <math.h>
/*{
this struck describe cofficients of 
quadratic equation: a*x^2 + b*x + c = 0
}*/
struct coeff
{
   double a,b,c;
};
//==============================================================================
/*{
it needs for safe roots quadratic equation
and number of them
}*/
struct root
{
   double x1,x2;
   char num;
};
//==============================================================================
/*{
this function calculate discriminant of 
quadratic equation
take cofficient of quadratic equation
}*/
double Discr(coeff K)
{
   return K.b * K.b - 4 * K.a * K.c;
}
//==============================================================================
double Roots(coeff K,double D,int n)
{
   if(n == 1)  return (-K.b + sqrt(D)) / (2 * K.a);
   if(n == 2)  return (-K.b - sqrt(D)) / (2 * K.a);
}
//==============================================================================
/*{
this function calculate roots of quadratic equation
if there ara two different roots roots.num = 2(namber of roots)
if there one root (two similar roots) roots.num = 1
else roots.num = 0
roots.x1 and roots.x2 safe roots
It return struct "root"
}*/
root equation(coeff koeff)
{
   root roots={};
   double discr=0;
   
     if(koeff.a == 0)                                        
      {
        if(koeff.b != 0)
        {
          roots.x1 = -koeff.c / koeff.b;
          roots.num = 1;                             
        }
         else roots.num = 0;
      }
       else 
       {
         discr = Discr(koeff); 
         if (discr>0)                                         //2 roots 
         {                                  
           roots.x1 = Roots(koeff,discr,1);
           roots.x2 = Roots(koeff,discr,2);
           roots.num = 2;   
         }
          else
           if(discr==0)
           {
             roots.x1=Roots(koeff,discr,1);              //1 root
             roots.x2=roots.x1;
             roots.num=1;                                       
           }       
           else 
            if(discr<0) roots.num=0;                    //0 root
        }        
   return roots;    
 }
//==============================================================================
/*{
main programm are working while all coefffisiants of 
quadratic equation are different from 0
}*/
main()
{    
      printf("ENTER \"0 0 0\"  TO EXIT\n");
      printf("please, enter 3 coefficients of quadratic equation\n"); 
      coeff  coeff={};
      root   roots={};
      do
      {
          scanf("%lg %lg %lg", &coeff.a, &coeff.b, &coeff.c);                       //entering       
          roots = equation(coeff);
          switch(roots.num)
            {
              case 2:printf("x1=%lg\nx2=%lg\n",roots.x1,roots.x2);break;
              case 1:printf("x=%lg\n",roots.x1);break;
              case 0:printf("the equation haven't roots\n");break;
              default: break;
            }
      }
      while((coeff.a!=0)||(coeff.b!=0)||(coeff.c!=0));

}
