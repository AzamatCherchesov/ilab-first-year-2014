/* Author : Perov A. A.
 *
 * Least common multiple seeker
 *
 * 24.10.2014
*/

#include <stdio.h>

int GCDseeker(int num1, int num2);

int LCMseeker(int num1, int num2);

/* calculates least commom multiple of 3 numbers
 *
 * takes numbers
 *
 * outputs their LCM
*/

int main()
{
    int num1 = 0, num2 = 0, num3 = 0;
    scanf("%d %d %d", &num1, &num2, &num3);
    int output = LCMseeker(LCMseeker(num1, num2), LCMseeker(num1, num3));
    printf("%d", output);
    return 0;
}

int GCDseeker(int num1, int num2)
{

    /* calculates greatest common divisior of 2 numbers
     * takes these numbers
     * returns GCD
     */

    int fuckit = 0, GCD = 0, mod = 0;
    if(num1 < num2)
    {
        fuckit = num2;
        num2 = num1;
        num1 = fuckit;
    }
    if (num1 % num2==0)
    {
        GCD = num2;
    }
    else
    {
        mod = (num1 % num2);
        while (num2 % mod !=0)
        {
            fuckit = mod;
            mod = num2 % mod;
            num2 = fuckit;
        }
    GCD = mod;
    }
    return (GCD);
}

int LCMseeker(int num1, int num2)
{

    /* calculates least common multiple of 2 numbers
     *
     * takes these numbers
     *
     * returns their LCM
    */

    int LMC = ((num1 * num2) / GCDseeker(num1, num2));
    return LMC;
}
