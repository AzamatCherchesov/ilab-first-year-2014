#include "command.h"
#include <stdio.h>

void replace (FILE *input, FILE *output)
{
	if (!(input && output))return;
	char line[MAX_COMMAND_SIZE] = {};
	int c = 0, i = 0;
	while (c != EOF)
	{
	  for (c = 0;c != ' ' && c != '\n' && c != EOF; c = fgetc(intput))
	  {
		line[i++] = c;
	  }
	  line[i++] = '/0';
	  if (c == ':'){}   //label i do it later
	  for (i = 0; i<NUM_OF_COMMAND; i++)
	  {
		  if (!strcmp(line,COMMANDS[i]))break;
	  }
	  fprintf(output,"%i ",i);
	  double number = 0;
	  switch(i)
	  {
	  case 0:							//push
		  fscanf(input,"%lg",&number);
		  fprintf(output, "%lg\n",number);
		  break;
	  case 1:break;						//pop
	  case 2:							//pushr
		  fscanf(input,"%lg",&number);
		  fprintf(output, "%lg\n",number);
		  break;
	  case 3:break;						//popr
	  case 4:break;						//mul
	  case 5:break;						//div
	  case 6:break;						//add
	  case 7:break;						//sub
	  default:break;
	  }
	}

}