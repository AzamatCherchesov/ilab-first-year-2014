#include <stdio.h>

//maximum element
int max(int a, int b)
{
	return (a > b) ? a : b;
}

//calculate answer
int num(int n, int k)
{
	int Y[50][50];

	for (int i = 1; i <= 49; i++)
		for (int j = 1; j <= 49; j++)
		{
		Y[i][j] = 0;
		}

	for (int i = 1; i <= 49; i++)
	{
		Y[i][1] = i;
	}

	int s = 0;
	for (int i = 1; i <= 49; i++)
	{
		s += (i < 2) ? 0 : (i - 2);
		Y[i][2] = s;
	}

	for (int i = max(k, 4); i <= n; i++)
	{
		for (int j = 3; j <= k; j++)
		{
			Y[i][j] = Y[i - 2][j] + Y[i - 2][j - 1] + Y[i - 3][j - 1];
		}
	}

		
	int f = 7;
	f = Y[n][k];
	return f;
}

int main()
{
	int n = 0, k = 0;
	int y = 0;
	n = 15;
	k = 4;
	y = num(n, k); 
	printf("%d\n", y);
	return 0;
}