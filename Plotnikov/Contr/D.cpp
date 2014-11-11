#include <stdio.h>

int num(int n, int k)
{
	int Y[50][50];

	for (int i = 0; i <= 49; i++)
	{
		Y[i][1] = i;
	}

	Y[1][2] = 0;

	for (int i = k; i <= n; i++)
	{
		for (int j = 2; j <= k; j++)
		{
			Y[i][j] = Y[i-1][j] + Y[i-1][j-1];
			//printf("%d %d %d ", i, j, Y[i][j]);
		}
		//printf("\n");
	}

	//printf("%d %d ", n, k);	
	int f = 7;
	f = Y[n][k];
	//printf("%d\n", f);
	return f;
}

/*long num(int n, int k)
{
	//printf("%d %d\n", n, k);
	if (k != 0)
	{
		long f = 0;
		if (n = k) { f = 1; }
		else f = num(n - 1, k) + num(n - 1, k - 1);
		//printf("%d %d %ld\n", n, k, f);
		return f;
	}
	else return 0;
}*/

int main()
{
	int n = 0, k = 0;
	int y = 0;
	//scanf("%d %d", &n, &k);
	n = 4;
	k = 2;
	y = num(n, k); 
	//printf("MAIN\n");
	printf("%d\n", y);
	return 0;
}