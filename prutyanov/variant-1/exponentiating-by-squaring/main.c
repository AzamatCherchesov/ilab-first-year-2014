/**
   Exponentiating by squaring

   @date 10.2014

   @copyright GNU GPL v2.0

   @author Viktor Prutyanov mailto:vitteran@gmail.com 
*/

#include <stdio.h>
#include "exp-by-sqr.h"
#include <stdlib.h>

int main()
{
    printf ("Enter base and power:\n");
    long unsigned int base = 0, power = 0;
    scanf ("%u %u", &base, &power);
    printf ("%u ^ %u= %u\n", base, power, pow(base, power));
    
    #ifdef _DEBUG
        system ("pause");
    #endif
    
    return 0;
}