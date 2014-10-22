# include <stdio.h>
# include <math.h>
# include <float.h>



//this function is a check if the discriminant is a zero
int proverka(double a,double b, double c)
{
    if (  fabs (b * b - 4 * a * c - 0.0) <= DBL_EPSILON * fmax( fabs(b * b - 4 * a *c ), fabs (0.0))  )
        return 0;
    else
        return 1;
}


//this function check if root is a zero or not
int if_zero(double koef1, double koef2)
{
    if (  fabs ( - koef2 / koef1 - 0.0) <= DBL_EPSILON*fmax( fabs( - koef2 / koef1 ), fabs (0.0))  )
        return 0;
    else
        return 1;
}


//this function counts roots of quadratic equation
void kvadr (double a, double b, double c)
{
 double x1, x2;

 if (proverka(a,b,c)==1)
 {

     if ((b * b - 4 * a * c)>0)
     {
        x1 = ( -b + sqrt(b * b - 4 * a * c )) / (2 *a ) ;
        x2 = ( -b - sqrt(b * b - 4 * a * c )) / (2 * a) ;
        printf ("x1= %lg x2= %lg",x1 , x2);
     }
     else
        printf("equation has not any roots");
 }

 else
 {
     x1= -b /( 2 * a);
     if (if_zero(b,2* a)==1)
        printf ("x= %lg",x1);
     else
        printf("x= %lg",0);
 };

}


//this function solves linear equation
void lin(double b, double c)
{

   double x1;

   if ((b==0)&&(c==0))
        printf(" the equation has an infinite number of roots ");
   if ((b==0)&&(c!=0))
        printf(" the equation has not any roots ");
   if (b!=0)
   {
       x1= -c /b;
       if (if_zero(c,b)==1)
            printf ("x= %lg",x1);
       else
            printf("x= %lg",0);
   };

}


int main()
{

  double a,b,c;

  printf ("enter the coefficients of the equation:\n");
  scanf("%lg %lg %lg", &a, &b, &c);
  if (a!=0)
    kvadr(a,b,c);
  else
    lin(b,c);

  return 0;

}
