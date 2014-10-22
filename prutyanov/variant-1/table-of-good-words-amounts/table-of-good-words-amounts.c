/**
   Program that determines does number contains full square or not.

   @date 10.2014

   @copyright GNU GPL v2.0

   @author Viktor Prutyanov mailto:vitteran@gmail.com 
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
    @brief Copies src array to dst array

    @param src is pointer to unsigned int source array
    @param dst is pointer to unsigned int destination array
    @param length is unsigned int length of array

    @return 0 if everything is OK, 1 if not
*/
int array_copy(unsigned int *src, unsigned int *dst, unsigned int length)
{
    if ((src == nullptr) || (dst == nullptr)) return 1;
    for (unsigned int i = 0; i < length; i++)
    {
        assert (0 <= i && i < length);
        dst[i] = src[i];
    }
    return 0;
}

/**
    @brief Prints src array without zero values

    @param src is pointer to unsigned int source array
    @param length is unsigned int length of array

    @return 0 if everything is OK, 1 if not
*/
int array_print(unsigned int *src, unsigned int length)
{
    if (src == nullptr) return 1;
    for (unsigned int i = 0; i < length; i++)
    {
        assert (0 <= i && i < length);
        if (src[i] != 0)
        {
            printf ("%u ", src[i]);
        }
    }
    return 0;
}

int main()
{
    unsigned int n = 0;

    printf ("Enter maximum length:\n");
    scanf ("%u", &n);
    
    unsigned int *array0 = (unsigned int *)calloc (n + 1, sizeof(unsigned int));
    unsigned int *array1 = (unsigned int *)calloc (n + 1, sizeof(unsigned int));
    unsigned int *array2 = (unsigned int *)calloc (n + 1, sizeof(unsigned int));

    array2[0] = 1;
    array1[0] = 1;
    array0[0] = 1;
    array1[1] = 1;
    
    printf ("1\n1 1\n");

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            array0[j] = array1[j] + array2[j - 1];
        }
        array_copy (array1, array2, n + 1);
        array_copy (array0, array1, n + 1);
        array_print (array0, n + 1);
        printf("\n");
    }

    free(array0);
    free(array1);
    free(array2);
    array0 = nullptr;
    array1 = nullptr;
    array2 = nullptr;

    #ifdef _DEBUG
        system ("pause");
    #endif
}