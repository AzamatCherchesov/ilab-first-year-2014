/**
*   
*   Program that determines whether it is possible to weigh this number on the scale with little weights 1 4 16 etc.
*
*   @date 10.2014
*
*   @copyright GNU GPL v2.0
*
*   @author Viktor Prutyanov mailto:vitteran@gmail.com 
*/

#include <stdio.h>
#include <stdlib.h>

/**
*   Function determines is it possible to weight
*
*   @param m is unsigned long number
*
*   @return integer value 1 if possible and 0 if impossible 
*/
int is_possible_to_weight(unsigned int m)
{
    if (m == 0)
    {
        return 1;
    }
    else if ((m - 2) % 4 == 0)
    {
        return 0;
    }
    else if (m % 4 == 0)
    {
        return is_possible_to_weight (m / 4);
    }
    else if ((m - 1) % 4 == 0)
    {
        return is_possible_to_weight ((m - 1) / 4);
    }
    else if ((m + 1) % 4 == 0)
    {
        return is_possible_to_weight ((m + 1) / 4);
    }
}

int main()
{
    unsigned int n = 0;
    printf("Enter number you want to weight on scales with two bowls and 1, 4, 16 etc. weights:\n");
    scanf("%u", &n);
    switch(is_possible_to_weight(n))
    {
        case 1:
            printf("YES\n");
            break;
        case 0:
            printf("NO\n");
            break;
        default:
            printf ("If you see this message it means that something went wrong.");
            break;
    }

    #ifdef _DEBUG
        system ("pause");
    #endif
}