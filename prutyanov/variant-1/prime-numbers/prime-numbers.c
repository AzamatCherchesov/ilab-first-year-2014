/**
*   Program for extracting prime numbers
*
*   @date 10.2014
*
*   @copyright GNU GPL v2.0
*
*   @author Viktor Prutyanov mailto:vitteran@gmail.com 
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


typedef enum result_t { OK = 0, NULL_PTR_PARAM = -1 }; 

/**
*   Function checks is number prime or not.
*   @param n is unsigned long integer number
*   @return integer value 1 if number is prime and 0 if number is composite of -1 if number isn't composite or prime 
*/
int is_prime(unsigned long int n)
{
    if (n == 0 || n == 1)
    {
        return -1;
    }
    else if (n % 2 == 0)
    {
        return 0;
    }
    else
    {
        for (int i = 3; i < floor (sqrt ((double)n) + 1); i += 2)
        {
            if (n % i == 0)
            {
                return 0;
            }
        }
        return 1;
    }
}

/**
*   Function extract prime numbers from array
*   @param in_array is source array of unsigned longints
*   @param out_array is array of unsigned longints with only prime numbers
*   @param n is uint number of elements
*   @param c is uint number of primes
*   @return result_t 0 if all is OK and -1 if one or more of params is nullptr
*/
result_t prime_numbers(unsigned long int *in_array, unsigned long int *out_array, unsigned int n, unsigned int *c)
{
    if (in_array == nullptr || out_array == nullptr)
    {
        return NULL_PTR_PARAM;
    }

    int j = 0;

    for (int i = 0; i < n; i++)
    {
        assert (0 <= i && i < n);
        if (is_prime (in_array[i]) == 1)
        {
            out_array[j] = in_array[i];
            j++;
        }
    }

    *c = j;

    return OK;
}


int main()
{
    unsigned int n = 0, c = 0;
    scanf ("%u", &n);

    long unsigned int *in_array = (long unsigned int *)calloc (n, sizeof(*in_array));
    long unsigned int *out_array = (long unsigned int *)calloc (n, sizeof(*out_array));

    for (int i = 0; i < n; i++)
    {
        assert (0 <= i && i < n);
        scanf ("%u", &in_array[i]);
    }

    prime_numbers (in_array, out_array, n, &c);

    for (int i = 0; i < c; i++)
    {
        assert (0 <= i && i < n);
        printf ("%u ", out_array[i]);
    }

    printf ("\n");

    #ifdef _DEBUG
        system ("pause");
    #endif

    return 0;
}