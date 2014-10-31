#include <stdio.h>
#include <stdlib.h>
#include "stack_the_fox.h"



int main()
{
    Stack* st = stack_ctor ( 4 );

    if ( st == NULL )
    {
        printf ( "No stack - no work." );

        exit ( -1 );
    }

    push ( st, 10 );
    push ( st, 20 );

    int k = 0;
    int i = 0;

    for ( i = 0; i < 10; i++ )
    {
        k = pop ( st );
        if ( k == ERR_EMPTY_STACK ) printf ( "I can't pop anything :(\n" );

        else
        {
            printf ( "%d\n", k );
        }
    }

    return 0;
}
