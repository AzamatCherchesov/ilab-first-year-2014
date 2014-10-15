//{===============================================================================
//! @file    solve.cpp
//!
//! @date    2014-10-14 00:08
//!
//! @author  Plotnikov Akim (419 DREC MIPT) <akim.plotnikov@phystech.edu>
//!
//! @name    Solve square equation
//!
//! @par     Programme prints square equation roots. 
//!
//! @note   "Error"  - this programme prints in case of scanned uncorrcect
//!					   coeficient (sample a = 0, b = 0, c = 2). 	
//!			"Infinity real roots"  - this programme prints 
//!                                    in case of infinitive amount ,
//!			"No real roots" printed in case of real roots absence. 
//}===============================================================================


#include <stdio.h>
#include <math.h>

//{=================================================================================
//! DIS - calculate the discriminant a square equation by its coefficients.
//!
//! @param     a   Equation a-coefficient
//! @param     b   Equation b-coefficient
//! @param     c   Equation c-coefficient
//! 
//! @return        discriminant a square equation
//!
//}=================================================================================

double DIS(double a, double b, double c)
{
	return (b * b - 4 * a * c); 
}


int main()
{
	printf("Enter 3 doubles: ");

	double a = 0, b = 0, c = 0;  
	scanf("%lg %lg %lg", &a, &b, &c);

	if ((a == 0) && (b == 0)) 
	{ 
		if (c == 0) { printf("Infinity real roots\n"); } 
		else printf("Error\n");
	}
	else 
		if (a == 0) { printf("%d\n", c / b); }
		else
		{
			if (DIS(a, b, c) < 0) { printf("No real roots\n"); }
			else 
			{
				double x1 = 0, x2 = 0;
				x1 = (-b - sqrt(DIS(a, b, c))) / (2 * a);
				x2 = (-b + sqrt(DIS(a, b, c))) / (2 * a);
				printf("x1= %lg, x2= %lg\n", x1, x2);
			}
		};

	return 0;
}