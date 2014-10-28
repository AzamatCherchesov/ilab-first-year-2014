/*Author : Perov A. A.
 *
 * quadratic equation solver
 *
 * 24.10.2014
*/
#include <stdio.h>
#include <math.h>

/*
 * if qudratic equation has 3 solutions, every real number is a solution
 * so this constant shows that every number is a solution
*/
const int everynumber = 3;

int solving(double a, double b, double c, double *x1, double *x2);

void output(double x1,double x2, int number);

/*solves equation ax^2+bx+c=0;
 *takes factors a, b, c
 *outputs solutions
*/
int main()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    scanf("%lg %lg %lg", &a, &b, &c);
    int solved = solving(a, b, c, &x1, &x2);
    output(x1, x2, solved);
    return 0;
}

int solving(double a, double b, double c, double *x1, double *x2)
{

/*solves equation ax^2+bx+c=0;
 *takes factors a, b, c
 *puts solutions in x1 and x2
 *returns number of roots
*/

    int number = 0;
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                number = everynumber;
            }
            else {
                number = 0;
            }
        }
        else {
            number = 1;
            *x1 = -c/b;
        }
    }
    else {
        double d = b * b - 4 * a * c;
        if (d < 0) {
            number = 0;
        }
        else if (d == 0) {
            number = 1;
            *x1=(-b)/(2*a);
        }
        else {
            number = 2;
            *x1 = (-b - sqrt(d))/(2 * a);
            *x2 = (-b + sqrt(d))/(2 * a);
        }
    }
    return (number);
}

void output(double x1,double x2, int number)
{

/*outputs solutions
 *takes solutions and their number
*/

    switch ( number )
    {
        case everynumber:
            printf("every number is a root");
            break;
        case 2:
            printf("x1 = %lg, x2 = %lg", x1, x2);
            break;
        case 1:
            printf("x = %lg", x1);
            break;
        default :
            printf("no roots");
    }
}
