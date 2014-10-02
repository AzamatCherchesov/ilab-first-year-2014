#include <stdio.h>
#include <math.h>

int plus(x11, x12) {
    printf ("%lg %lg", x11, x12); }

int null(x) {
    printf ("%lg", x); }

int minus(x) {
    printf ("No solution"); }

int main(void) {
    double a, b, c, x1, x2;
    scanf ("%lg %lg %lg", &a, &b, &c);
    if (a==0) {
        if (b==0) {minus(b);}
        else 
            {x1=(-c/b);
            null(x1);}}
    else 
        {
        double d=b*b-4*a*c;
        if (d<0) {minus(d);};
        if (d==0) {x1=-b/(2*a);
                  null (x1);};
        if (d>0) {x1=(-b+sqrt(d))/(2*a);
                  x2=(-b-sqrt(d))/(2*a);
                  plus (x1, x2); }};


return 0;
}
