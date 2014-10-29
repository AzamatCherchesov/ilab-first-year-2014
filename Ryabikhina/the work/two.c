#include <stdio.h>
#include <assert.h>


//the function take the number
//returns degrees of two in massive

 int* solve( int n)
 {

  int i = 0, j = 0, k = 1 ,number = 0;
  int* a= ( int ) calloc ( 32, sizeof( int ) );
  int* b= ( int ) calloc ( 32, sizeof( int ) );

//the binary representation of a number

  while ( n >= 1 )
  {

    if ( n % 2 == 0 )
        {
            a[i] = 0;
            i++;
        }

    else
        {
            a[i] = 1;
            i++;
        };

    n = ( n - n % 2 ) / 2;

  }

//formation of degrees

  for ( j = 0; j < i; j++ )
  {

   assert ( ( a[j] == 0 ) || (a[j] == 1) );

   if ( a[j] != 0 )
   {
       b[number]= a[j] * k;
       number++;
   }

   k = k * 2;

  }

  free(a);

  return b;

 }


int main()
{
    int n = 0, i = 0;
    int* d= (int) calloc ( 32, sizeof(int) );

    printf("write the number: ");
    scanf("%d",&n);

    assert ( n > 0 );

    d = solve(n);

//printing the answer
    while ( d[i] != 0 )
      {
        printf("%d ", d[i] );
        i++;
      }


    free ( d );

    return 0;
}
