#include <stdio.h>
#include <math.h>

const int EVERYONE = -1;
const int nCoeff = 3;

int out (int num, double x1, double x2);
int solveSquare(double a[nCoeff], double* x1, double* x2);

int main() {
    double a[nCoeff] = { 0, 0, 0 };
    while (scanf("%lg",&a[0]) == 0) {       //if there is missprint
        scanf("%*s");                       // program works right
    }
    while (scanf("%lg",&a[1]) == 0) {
        scanf("%*s");
    }
    while (scanf("%lg",&a[2]) == 0) {
        scanf("%*s");
    }
    double x1 = 0, x2 = 0;
    int nroots = solveSquare(a, &x1, &x2);
    out(nroots, x1, x2);
    return (0);
}

int solveSquare(double a[nCoeff], double* x1, double* x2) {
    if (a[0] == 0) {
        if (a[1] == 0 ) {
            if (a[2] == 0) {
                return EVERYONE;
            }
            else {
                return 0;
            }
        }
        else {
            *x1 = -a[2]/a[1];
            return 1;
        }
    }

    else {
        double d = 0;
        d = a[1] * a[1] - 4 * a[0] * a[2];
        if (d < 0) {
            return 0;
        }
        else if (d == 0) {
            *x1 = -a[1] / 2/a[0];
            return 1;
        }
        else {
            *x1 = (-a[1] + sqrt(d))/ 2/a[0];
            *x2 = (-a[1] - sqrt(d))/ 2/a[0];
            return 2;
        }
    }
}

int out(int nroots, double x1, double x2) {
    if (nroots == EVERYONE) {
        printf ("Any real number");
    }
    else if (nroots == 0) {
        printf ("No real roots");
    }
    else if (nroots == 1) {
        printf ("x = %lg", x1);
    }
    else {
        printf ("x1 = %lg, x2 = %lg", x1, x2);
    }
    return 0;
}
