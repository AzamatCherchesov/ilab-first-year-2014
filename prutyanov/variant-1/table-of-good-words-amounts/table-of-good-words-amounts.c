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
    Function that determines is word good of not (doesn't contain 2 units streak and contains determined units)

    @param word is unsigned int for determination
    @param length is unsigned int length of word
    @param units is amount of units in word to be good

    @return 1 if word is good, 0 if isn't
*/
int is_good_word(unsigned int word, unsigned int length, unsigned int units);

/**
    Realisation power function for only unsigned ints as base and exponent.

    @param base is unsigned int base
    @param n is unsigned int exponent

    @return unsigned int base^n
*/ 
unsigned int power(unsigned int base, unsigned int n);

/**
    Function that calculates amount of good words with given length and amount of units

    @param length is unsigned int length of word
    @param units is unsigned int amount of units 

    @return amount of good words with given parameters
*/
unsigned int good_words_amount(unsigned int length, unsigned int units);

/**
    Function that calculates length of word binary presentation

    @param word is unsigned int number for calculating length

    @return int length of binary word
*/
unsigned int word_length(unsigned int word);

/**
    Function that finds 2 units streak

    @param word is unsigned int number for streak find
    @param length is unsigned int length of word

    @return 1 if 2 unit streak exist, 0 if doesn't exist
*/
int is_2_units_streak(unsigned int word, unsigned int length);

/**
    Function that calculates amount of units in binary presentation of number

    @param word is unsigned int number for calculating amount of units
    @param length is unsigned int length of word
    
    @return unsigned int amount of units
*/
unsigned int units_amount(unsigned int word, unsigned int length);

int main()
{
    unsigned int n = 0;
    unsigned int amount = 0;

    printf ("Enter maximum length:\n");
    scanf ("%u", &n);

    for (unsigned int i = 0; i <= n; i++)
    {
        for (unsigned int j = 0; j <= i; j++)
        {
            amount = good_words_amount (i, j);
            if (amount) printf ("%u ", amount);
        }
        printf("\n");
    }

    #ifdef _DEBUG
        system ("pause");
    #endif
}


int is_good_word(unsigned int word, unsigned int length, unsigned int units)
{
    if ((units_amount (word, length) == units) && !is_2_units_streak (word, length))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

unsigned int power(unsigned int base, unsigned int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return power (base, n - 1) * base;
    }
}

unsigned int good_words_amount(unsigned int length, unsigned int units)
{
    unsigned int amount = 0;
    for (int w = 0; w < power (2, length); w++)
    {
        if (is_good_word(w, length, units))
        {
            amount++;
        }
    }
    return amount;
}

unsigned int word_length(unsigned int word)
{
    unsigned int i = 0;
    while (power (2, i) < word)
    {
        i++;
    }
    return i;
}

int is_2_units_streak(unsigned int word, unsigned int length)
{
    for (int i = 1; i < length; i++)
    {
        if ((word & (1 << i)) && (word & (1 << i - 1))) return 1;
    }
    return 0;
}

unsigned int units_amount(unsigned int word, unsigned int length)
{
    unsigned int units = 0;
    for (int i = 0; i < length; i++)
    {
        if (word & (1 << i)) units++;
    }
    return units;
}