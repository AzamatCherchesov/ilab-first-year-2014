/**
   Exponentiating by squaring

   @date 10.2014

   @copyright GNU GPL v2.0

   @author Viktor Prutyanov mailto:vitteran@gmail.com 
*/

unsigned int pow(unsigned int base, unsigned int power)
{
    unsigned int result = 1;
    while (power != 0) 
    {
        if (power & 1)
        {
            power--;
            result *= base;
        }
        else
        {
            power >>= 1;
            result *= result;
        }
        
    }
    return result;
}