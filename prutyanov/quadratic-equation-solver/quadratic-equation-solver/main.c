/**
*   Program for solving quadratic and linear equations.
*
*   @date 09.2014 - 10.2014
*
*   @copyright GNU GPL v2.0
*
*   @author Viktor Prutyanov mailto:vitteran@gmail.com 
*/

#include <math.h>
#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include <assert.h>

typedef enum result_t {ONE_ROOT = 1, INFINITY_SET = -1, NO_ROOTS = 0, TWO_ROOTS = 2, INVALID_EQUATION = -2, NULL_PTR_PARAMS = -3};

typedef struct roots_t ///Struct that describes pair of roots 
{
    double x1; ///First root
    double x2; ///Second root
};

/**
*   @brief Auxillary function that calculates discriminant.
*   @param a is first double coefficient
*   @param b is second double coefficient
*   @param c is third double coefficient
*   @return double discriminant
*/
double discriminant (double a, double b, double c);

/**
*   @brief An equation solving function. 
*   @param *coeffs is an array of double that describes coefficients
*   @param *roots is a pointer to roots_t (struct of roots). Solution will be there.
*   @param n_coeffs is integer number of coefficients
*   @param epsilon is double value that describes accuracy of calculations
*   @return number of roots or INFINITY_SET or INVALID_EQUATION (can't solve) or NULL_PTR_PARAM (at least 1 of params is nullptr).
*/

result_t solve_equation (double *coeffs, int n_coeffs, roots_t *roots, double epsilon)
{

    if ((coeffs == nullptr) || (roots == nullptr)) return NULL_PTR_PARAMS;

    for (int i = 3; i < n_coeffs; i++) //Function does not solve equations with max power more then 2.
    {
        assert ((0 <= i && i < n_coeffs, "Array index out of bounds"));
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
                return INFINITY_SET;
            }
            else
            {
                return NO_ROOTS;
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

int main (void)
{
    int status = 0, n_coeffs = 0;
    double eps = 0;
    roots_t roots = { };

    printf ("Welcome to quadratic and linear equation solver!\n");
    printf ("Enter number of coefficients:\n");
    scanf ("%d", &n_coeffs);
    double *coeffs = (double *)calloc (n_coeffs, sizeof(*coeffs));
    assert (coeffs != nullptr);

    printf("Enter coefficients in order from bigger to smaller power:\n");
    for (int i = n_coeffs - 1; i >= 0; i--)
    {
        assert ((0 <= i && i < n_coeffs, "Array index out of bounds"));
        scanf ("%lf",  &coeffs[i]);
    }

    printf ("Enter epsilon, if epsilon = 0 then uses default epsilon (DBL_EPSILON).\n");
    printf ("Epsilon means least value that interpretes as 0.\n");
    printf ("For further information, see https://en.wikipedia.org/wiki/Machine_epsilon \n");

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
            printf ("If you see this message it means that something went wrong.");
            break;
    }
    
    #ifdef _DEBUG
        system("pause");
    #endif

    return 0;
}

double discriminant (double a, double b, double c)
{

    return b * b - 4.0 * a * c;
}