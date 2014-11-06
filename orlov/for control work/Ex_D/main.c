#include <stdio.h>

void Ex_D(int n, int k);

int main(void)
{
  int n = 0, k = 0;
  scanf("%i %i",&n, &k);
  Ex_D(n,k);

  return 0;
}


int Ex_D(int n, int k)
{
    const int N = 90, K = 10;
    int c[N][K]={};
    int i = 0, j = 0;

    for (i = 0;i < n;i++)
      for (j = 0;j < k;j++)
      {
          if (j == 0)  c[i][j] = 0;
          else
          if (i == 0)  c[i][j] = 1;
          else
          if (j == 1 && (i > 0 && i < 10))c[i][j] = 1;
          else
          c[i][j] = 0;
      }
    if (k == 0 || n == 0) return c[n][k];
    while (!c[n][k])
    {
      i++;
      for (j = 1; j < k; j++)
      {
          c[i][j]=c[i][j-1]+c[i-1][j-1]+c[i-2][j-1]+c[i-3][j-1]+c[i-4][j-1]+c[i-5][j-1]+c[i-6][j-1]+c[i-7][j-1]+c[i-8][j-1]+c[i-9][j-1];
      }
    }
    return c[k][n];
}
