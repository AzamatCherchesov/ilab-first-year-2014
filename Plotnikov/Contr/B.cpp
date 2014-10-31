#include <stdio.h>

//решение задачи B варианта #5
int main()
{
	unsigned long n, i, s = 0;
	scanf("%lld", &n);
	for (i = 1; i <= n; i++)
	{
		if (n % i == 0) { s = s + i; };
	};
	printf("%lld\n", s);
}