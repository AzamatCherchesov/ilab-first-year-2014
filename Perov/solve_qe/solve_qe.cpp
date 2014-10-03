
#include <stdio.h>
#include <math.h>

const double everynumber = 3;

int output(double number,double x1,double x2)
    {

    if (number == 3) {
        printf("every number is a root");
    }
    else if (number == 0) {
        printf("no roots");
    }
    else if (number == 1) {
        printf("x = %lg", x1);
    }
    else {
        printf("x1 = %lg, x2 = %lg", x1, x2);
    }
    return 0;
    }

int main()
{

    double a = 0, b = 0, c = 0;
    int number = 0;
    double x1 = 0, x2 = 0;
    scanf("%lg %lg %lg", &a, &b, &c);
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
            x1 = -c/b;
        }
    }
    else {
        double d = b * b - 4 * a * c;
        if (d < 0) {
            number = 0;
        }
        else if (d == 0) {
            number = 1;
            x1=(-b)/(2*a);
        }
        else {
            number = 2;
            x1 = (-b - sqrt(d))/(2 * a);
            x2 = (-b + sqrt(d))/(2 * a);
        }
    }
    output(number, x1, x2);
    return(0);

}
