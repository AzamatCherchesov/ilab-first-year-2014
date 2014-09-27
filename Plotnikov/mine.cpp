#include <stdio.h>
#include <math.h>
#include <conio.h>


int main()
{
	printf("Enter 3 doubles: ");

	double a=0,b=0,c=0;
	scanf("%lg %lg %lg", &a, &b, &c);

	if (a == 0) {printf("%d", c/b);}
	else {
		double d = 0;
		d = b*b-4*a*c;
		if (d<0) {printf("Error");}
		else { 
			double x1 = 0, x2 = 0;
			x1 = (-b-sqrt(d))/(2*a);
			x2 = (-b+sqrt(d))/(2*a);
			printf("x1= %lg, x2= %lg", x1,x2);}
	};
	_getch();
	return(0);
}