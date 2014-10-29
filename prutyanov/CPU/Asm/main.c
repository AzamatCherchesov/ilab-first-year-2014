/**
*   Program for creation encyclopedia of russian XIX century life (A.S.Pushkin "Eugene Onegin")
*
*   @date 10.2014
*
*   @copyright GNU GPL v2.0
*
*   @author Viktor Prutyanov mailto:vitteran@gmail.com 
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf ("Usage:\n\tasm <input file> <output file>\n");
        #ifdef _DEBUG
            system ("pause");
        #endif
        return 0;
    }
    
    FILE *in_file  = fopen(argv[1], "r");
    FILE *out_file = fopen(argv[2], "wb");
    if (in_file == nullptr || out_file == nullptr) 
    {
        printf ("One or more incorrect files.\n");

        fcloseall();
        in_file = nullptr;
        out_file = nullptr;

        #ifdef _DEBUG
            system ("pause");
        #endif
        return 0;
    }

    printf("Input is %s, output is %s\n", argv[1], argv[2]);

    bool next_is_command = true;
    char command[5];
    double arg = 0;
    double val = 0;

    while (!feof (in_file))
    {
        if (next_is_command)
        {
            fscanf (in_file, "%s", &command);
            #define DEF_CMD(cmd, num, code, name, args)                  \
                if (strcmp (command, name) == 0)                          \
                {                                                          \
                    val = num;                                              \
                    fwrite ((void *)(&val), sizeof (double), 1, out_file);   \
                    if (args == 1) next_is_command = false;                   \
                }
            #include "commands.h"
            #undef DEF_CMD
        }
        else
        {
            fscanf (in_file, "%lf", &arg);
            fwrite ((void *)(&arg), sizeof (double), 1, out_file); 
            next_is_command = true;
        }
    }

    
    fcloseall();
    in_file = nullptr;
    out_file = nullptr;

    #ifdef _DEBUG
     system ("pause");
    #endif
    return 0;
}