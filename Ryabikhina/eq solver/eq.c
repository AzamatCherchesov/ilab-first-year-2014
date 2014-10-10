# include <stdio.h>
# include <math.h>

# define DISKR(koef1,koef2,koef3)     ( ( ( koef2 )*( koef2 ) ) - ( 4*( koef1 )*( koef3 ) ) );

//function which counts two roots
void two_roots (double koef1, double koef2, double D)
{
   double x1, x2, temp;

   x1=(-koef2+sqrt(D))/(2*koef1);
   x2=(-koef2-sqrt(D))/(2*koef1);
   if (x1>x2)
   {
     temp=x1;
     x1=x2;
     x2=temp;
   };

  printf("%lg %lg",x1,x2);

}

//function which counts one root
void one_root(double koef1, double koef2)
{
   double x1;

   x1=(-koef2/koef1);
   if (koef2==0) x1=0;

   printf("%lg",x1);
}

//the case of absence of roots
void no_roots()
{
    printf("NO");
}

// the case of many endless roots
void many_roots()
{
    printf("R");
}

int main()
{
  double a,b,c,D;

  scanf("%lg %lg %lg", &a, &b, &c);
  if (a!=0)
    {
      D = DISKR(a,b,c);
        if (D>0) two_roots (a, b, D);
        if (D<0) no_roots();
        if (D==0) one_root(2*a, b);
    };
  if (a==0)
    {
       if ((b==0)&&(c==0)) many_roots();
       if ((b==0)&&(c!=0)) no_roots();
       if (b!=0) one_root(b,c);
    };
  return 0;
}
