#include <stdio.h>


#define PUSH 0x0001
#define  ADD 0x0002
#define  MUL 0x0003
#define  SUB 0x0004
#define  DIV 0x0005
#define  POP 0x0006
#define JUMP 0x0007
#define CALL 0x0008
#define  END 0x0009


int main ()

{
    FILE* input = fopen ( "C:\\Project\\asmblr\\text of programm.txt", "r" );
    FILE* output = fopen ( "C:\\Project\\asmblr\\corrected.txt", "wb" );

    if ( !input )

    {

        printf ( "the input file wasn't opened" );
        return 0;

    }

    if ( !output )

    {

        printf ( "the input file wasn't opened" );
        return 0;

    }



    char txt [ 100 ]= "1";

    int result_of_reading = 0;
    int num = 0;

    while ( 1 )
    {
        result_of_reading = fscanf ( input, "%s", txt );

        if ( result_of_reading < 1 )

        {

            break;

        }


        if ( strcmp ( txt, "END" ) == 0 )

        {

            num = END;

            fwrite ( &num, sizeof ( int ), 1, output );

            break;

        }


        if ( strcmp ( txt, "PUSH" ) == 0 )

        {

            num = PUSH;

        }

        else if ( strcmp ( txt, "ADD" ) == 0 )

        {

            num = ADD;

        }

         else if ( strcmp ( txt, "MUL" ) == 0 )

        {

            num = MUL;

        }

         else if ( strcmp ( txt, "DIV" ) == 0 )

        {

            num = DIV;

        }

        else if ( strcmp ( txt, "SUB" ) == 0 )

        {

            num = SUB;

        }

        else if ( strcmp ( txt, "POP" ) == 0 )

        {

            num = POP;

        }

        else if ( strcmp ( txt, "JUMP" ) == 0 )

        {

            num = JUMP;

        }

        else if ( strcmp ( txt, "CALL" ) == 0 )

        {

            num = CALL;

        }

        else

        {

            sscanf ( txt, "%d", &num );


        }

        fwrite ( &num, sizeof ( int ), 1, output );

    }


    fclose ( input );
    fclose ( output );

    return 0;

}
