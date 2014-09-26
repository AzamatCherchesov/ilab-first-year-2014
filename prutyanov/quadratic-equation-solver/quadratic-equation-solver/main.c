#include <math.h>
#include <stdio.h>
#include <float.h>
#include <stdlib.h>

//Equation solving

typedef struct roots_t roots_t;

struct roots_t ///Struct that describes pair of roots 
{
    double x1; ///First root
    double x2; ///Second root
};

const int ONE_ROOT = 1, INFINITY_SET = -1, NO_ROOTS = 0, TWO_ROOTS = 2, INVALID_EQUATION = -2, NULL_PTR_ARGUMENTS = -3;

double discriminant (double a, double b, double c)
{
/**
*    @param a is first coefficient
*    @param b is second coefficient
*    @param c is third coefficient
*/
    return b * b - 4.0 * a * c;
}

int solve_equation (double *coeffs, int n_coeffs, roots_t *roots, double epsilon)
{
/**
*    @param *coeffs is an array of coefficients 
*    @param *roots is a pointer to struct of roots 
*    @param n_coeffs is number of coefficients
*    @param epsilon describes accuracy of calculations
*/
    if ((coeffs == nullptr) || (roots == nullptr)) return NULL_PTR_ARGUMENTS;

    for (int i = 3; i < n_coeffs; i++) //If there exist coefficients roots with a degree higher than 2 then the equation can not be solved by this function
    {
        if (coeffs[i] != 0)
        {
            return INVALID_EQUATION;
        }
    }

    double a = 0, b = 0, c = 0;

    if (n_coeffs == 2)
    {
        a = 0;
        b = coeffs[1];
        c = coeffs[0];
    }
    else if (n_coeffs == 1)
    {
        a = 0;
        b = 0; 
        c = coeffs[0];
    }
    else if (n_coeffs == 0)
    {
        return INVALID_EQUATION;
    }
    else
    {
        a = coeffs[2];
        b = coeffs[1];
        c = coeffs[0];
    }

    if (fabs (a) <= epsilon) //Linear equation
    {
        if (fabs (b) <= epsilon)
        {
            if (fabs (c) <= epsilon)
            {
                return INFINITY_SET; //Infinity set
            }
            else
            {
                return NO_ROOTS; //No roots
            }
        }
        else
        {
            roots->x1 = -c/b; //Linear equation with one root
            roots->x2 = -c/b;
            return ONE_ROOT;
        }
    }
    else //Quadratic equation
    {
        double d = discriminant (a, b, c);
        if (d >= 0)
        {
            roots->x1 = (-b + sqrt (d)) / (a * 2.0);
            roots->x2 = (-b - sqrt (d)) / (a * 2.0); //Two roots
            return TWO_ROOTS;
        }
        else
        {
            return NO_ROOTS;
        }
    }
}

int main (void)
{
    int status = 0, n_coeffs = 0;
    double eps = 0, *coeffs;
    roots_t roots = { };

    printf ("Enter number of coefficients:\n");
    scanf("%d", &n_coeffs);
    coeffs = (double *)calloc (n_coeffs, sizeof(*coeffs));

    printf("Enter coefficients:\n");
    for (int i = n_coeffs - 1; i >= 0; i--)
    {
        scanf("%lf",  &coeffs[i]);
    }

    printf ("Enter epsilon, if epsilon = 0 then uses default epsilon (DBL_EPSILON):\n");
    scanf ("%lf", &eps);
    if (eps == 0) eps = DBL_EPSILON;

    status = solve_equation (coeffs, n_coeffs , &roots, eps);

    free (coeffs);
    coeffs = nullptr;

    printf ("Result:\n");

    switch (status)
    {
        case TWO_ROOTS:
            printf ("x1 = %f\nx2 = %f\n", roots.x1, roots.x2);
            break;
        case ONE_ROOT:
            printf ("x = %f\n", roots.x1);
            break;
        case NO_ROOTS:
            printf ("Equation has no real roots.\n");
            break;
        case INFINITY_SET:
            printf ("Infinity set of roots.\n");
            break;
        case INVALID_EQUATION:
            printf ("The equation you printed is not a quadratic or linear equation.\n");
            break;
        default:
            break;
    }

    system("pause");
    return 0;
}