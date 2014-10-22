#include <stdio.h>


//the function lays out the number on the power of two
 void solve( unsigned int n)
 {

  int a[32], k, i;

  k = 0;
  while (n > 0)
  {
    i = 1;
    while (i * 2 <= n)
        i = i * 2;
    a[k] = i;
    k++;
    n = n - i;
  };
  for (i = k - 1; i >= 0; i--)
    printf("%d ", a[i]);
 }

main()
{
    unsigned int n;

    printf("write the number: ");
    scanf("%u",&n);
    solve(n);

    return 0;
}
