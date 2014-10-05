/**
   Program that determines does number contains full square or not.

   @date 10.2014

   @copyright GNU GPL v2.0

   @author Viktor Prutyanov mailto:vitteran@gmail.com 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
   Function that determines is number square-free or not.

   @param m unsigned int number

   @return 1 if number is square-free 0 if not
*/
int is_square_free(unsigned int m)
{
    for (int i = 2; i < m; i++)
    {
        if (m % (i*i) == 0)
        {
            return 0;
        }    
    }
    return 1;
}

int main()
{
    unsigned int n = 0;
    printf("Enter positive number you want to determine does it contains square or not:\n");
    scanf("%u", &n);
    switch(is_square_free(n))
    {
        case 1:
            printf("NO\n");
            break;
        case 0:
            printf("YES\n");
            break;
        default:
            printf ("If you see this message it means that something went wrong.");
            break;
    }

    #ifdef _DEBUG
        system ("pause");
    #endif
}