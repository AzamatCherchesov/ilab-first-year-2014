#include <stdio.h>

int main()
{
	long long n, i, s = 0;
	scanf("%lld", &n);
	for (i = 1; i <= n; i++)
	{
		if (n%i == 0) { s = s + i; };
	};
	printf("%lld\n", s);
}