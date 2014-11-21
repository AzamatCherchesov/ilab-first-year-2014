#pragma one
#include "stack_double.h"
#include "command.h"

int main()
{
   FILE *input = fopen("program.txt","r");
   FILE *output = fopen("program.asm",""w);

   replace(input,output);

   fclose(input);
   fclose(output);
	return 0;
}