#include <math.h>
#include <stdio.h>
#include <float.h>

//Equation ax^2+bx+c=0 solving

const int ONE_ROOT = 1, INFINITY_SET = -1, NO_ROOTS = 0, TWO_ROOTS = 2, NULL_PTR = -2;

double discriminant (double a, double b, double c)
{
    return b * b - 4.0 * a * c;
}

int solve (double a, double b, double c, double *x1, double *x2, double epsilon)
{
    double d = 0;

    if ((x1 == NULL) || (x2 == NULL))
    {
        return NULL_PTR;
    }

    if (fabs (a) <= epsilon) //Linear equation
    {
        if (fabs (b) <= epsilon)
        {
            if (fabs (c) <= epsilon)
            {
                *x1 = 0;
                *x2 = 0;
                return INFINITY_SET; //Infinity set
            }
            else
            {
                *x1 = 0;
                *x2 = 0;
                return NO_ROOTS; //No roots
            }
        }
        else
        {
            *x1 = -c/b; //Linear equation with one root
            *x2 = -c/b;
            return ONE_ROOT;
        }
    }
    else //Quadratic equation
    {
        d = discriminant (a, b, c);
        if (d >= 0)
        {
            *x1 = (-b + sqrt (d)) / (a * 2.0);
            *x2 = (-b - sqrt (d)) / (a * 2.0); //Two roots
            return TWO_ROOTS;
        }
        else
        {
            *x1 = 0;  //No root
            *x2 = 0;
            return NO_ROOTS;
        }
    }
}

int main (void)
{
    int status = 0;
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0, eps = 0;

    printf ("a b c epsilon\n");
    printf ("If epsilon = 0 then uses default epsilon (DBL_EPSILON)\n");
    scanf ("%lf %lf %lf %lf", &a, &b, &c, &eps);
    if (eps == 0) eps = DBL_EPSILON;
    status = solve (a, b, c, &x1, &x2, eps);
    if (status == TWO_ROOTS)
    {
        printf ("x1 = %f\nx2 = %f\n", x1, x2);
    }
    else if (status == ONE_ROOT)
    {
        printf ("x = %f\n", x1);
    }
    else if (status == NO_ROOTS)
    {
        printf ("Equation has no real roots\n");
    }
    else if (status == INFINITY_SET)
    {
        printf ("Infinity set of roots\n");
    }
    getchar();
    getchar();
    return 0;
}

