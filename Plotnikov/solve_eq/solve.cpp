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
//! @note   "Infinity real roots"  - this programme prints 
//!                                    in case of infinitive amount ,
//!			"No real roots" printed in case of real roots absence. 
//}===============================================================================


#include <stdio.h>
#include <math.h>

//#define MYCH 0 

#ifndef MYCH 
#define MYCH 1
#endif

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

double dis(double a, double b, double c)
{
	return (b * b - 4 * a * c); 
}

//{=================================================================================
//! roots - calculate number of roots a square equation by its coefficients.
//!
//! @param     a   Equation a-coefficient
//! @param     b   Equation b-coefficient
//! @param     c   Equation c-coefficient
//! 
//! @return        number of roots
//!
//}=================================================================================

int roots(double a, double b, double c)
{
	if ((a == 0) && (b == 0))
	{
		if (c == 0) { return -1; }
		else return 0;
	}
	else
		if (a == 0) { return 1; }
		else
		{
			if (dis(a, b, c) < 0) { return 0; }
			else
			{
				if (dis(a, b, c) == 0) { return 1; }
			}
		};
}

//{=================================================================================
//! solve - calculate root with number n a square equation by its coefficients.
//!
//!	@param	   n   root number
//! @param     a   Equation a-coefficient
//! @param     b   Equation b-coefficient
//! @param     c   Equation c-coefficient
//! 
//! @return        root with nomber n
//! 
//}=================================================================================

double solve(int n, double a, double b, double c)
{
	if (a == 0) { return b / c; }
	else
	{
		if (n == 1) { return ((-b - sqrt(dis(a, b, c))) / (2 * a)); }
		else { return ((-b + sqrt(dis(a, b, c))) / (2 * a)); };
	}
}

int main()
{
	
	if (MYCH == 0) { printf("Enter 3 solve equation coefficients: "); };

	double a = 0, b = 0, c = 0;  
	scanf("%lg %lg %lg", &a, &b, &c);

	if (roots(a, b, c) == 0) { printf("No real roots\n"); }
	else 
		if (roots(a, b, c) == -1) { printf("Infinity roots\n"); }
		else 
			if (roots(a, b, c) == 1) { printf("x = %lg\n", solve(1, a, b, c)); }
			else
			{
				double x1 = 0, x2 = 0;
				x1 = solve(1, a, b, c);
				x2 = solve(2, a, b, c);
				if (MYCH != 0) { printf("%lg %lg\n", x1, x2); }
				else { printf("x1 = %lg, x2 = %lg\n", x1, x2); };
			};

	return 0;
}