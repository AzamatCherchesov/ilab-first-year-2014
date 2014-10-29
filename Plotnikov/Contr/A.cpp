#include <stdio.h>

int main()
{
	long long n, i = 0;
	double x = 0, s = 1, p = 1;

	scanf("%lld %lg", &n, &x);

	for (i = 1; i <= n; i++)
	{
		p = p * (x / i);
		s = s + p;
	};

	printf("%6lf\n", s);
}