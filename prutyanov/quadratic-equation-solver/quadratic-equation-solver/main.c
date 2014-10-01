#include <math.h>
#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <assert.h>

typedef enum result_t {ONE_ROOT = 1, INFINITY_SET = -1, NO_ROOTS = 0, TWO_ROOTS = 2, INVALID_EQUATION = -2, NULL_PTR_ARGUMENTS = -3};

typedef struct roots_t ///Struct that describes pair of roots 
{
    double x1; ///First root
    double x2; ///Second root
};

/**
*   Auxillary function that calculates discriminant.
*   @param a is first double coefficient
*   @param b is second double coefficient
*   @param c is third double coefficient
*   @return double discriminant
*/
double discriminant (double a, double b, double c);

/**
*   An equation solving function.   
*   @param *coeffs is an array of double that describes coefficients
*   @param *roots is a pointer to roots_t (struct of roots) 
*   @param n_coeffs is integer number of coefficients
*   @param epsilon is double value that describes accuracy of calculations
*/
result_t solve_equation (double *coeffs, int n_coeffs, roots_t *roots, double epsilon);


result_t solve_equation (double *coeffs, int n_coeffs, roots_t *roots, double epsilon)
{

    if ((coeffs == nullptr) || (roots == nullptr)) return NULL_PTR_ARGUMENTS;

    for (int i = 3; i < n_coeffs; i++) //If there exist coefficients roots with a degree higher than 2 then the equation can not be solved by this function
    {
        assert (0 <= i && i <= n_coeffs);
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
        if (d > epsilon)
        {
            roots->x1 = (-b + sqrt (d)) / (a * 2.0);
            roots->x2 = (-b - sqrt (d)) / (a * 2.0); //Two roots
            return TWO_ROOTS;
        }
        else if (-epsilon <= d && d <= epsilon)
        {
            roots->x1 = (-b) / (a * 2.0);
            roots->x2 = (-b) / (a * 2.0); //Two equivalent roots
            return ONE_ROOT;
        }
        else
        {
            return NO_ROOTS;
        }
    }
}

double discriminant (double a, double b, double c)
{

    return b * b - 4.0 * a * c;
}

int main (void)
{
    int status = 0, n_coeffs = 0;
    double eps = 0;
    roots_t roots = { };

    printf ("Welcome to quadratic and linear equation solver!\n");
    printf ("Enter number of coefficients:\n");
    scanf("%d", &n_coeffs);
    double *coeffs = (double *)calloc (n_coeffs, sizeof(*coeffs));
    assert (coeffs != nullptr);

    printf("Enter coefficients:\n");
    for (int i = n_coeffs - 1; i >= 0; i--)
    {
        assert (0 <= i && i <= n_coeffs);
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
    
    #ifdef _DEBUG
        system("pause");
    #endif

    return 0;
}