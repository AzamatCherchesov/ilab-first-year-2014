#include <stdio.h>
#include <stdlib.h>
#include "stack_the_fox.h"


#define ARRAY_SIZE 14
#define STACK_SIZE 10

#define MAX_NUM 1200



Stack* test_ctor ( int sz );

void test_push ( Stack* st, int* arr, int num );

void test_pop ( Stack* st, int num );



int main()
{
    Stack* st = test_ctor ( STACK_SIZE );


    int* arr = (int*) calloc ( ARRAY_SIZE, sizeof (int) );

    int i = 0;

    for ( i = 0; i < ARRAY_SIZE; i++ )
    {
        arr[i] = rand () % MAX_NUM;
    }


    test_push ( st, arr, ARRAY_SIZE );

    dump_st ( st );

    test_pop ( st, ARRAY_SIZE + 4 );

    //test_push ( st, arr, ARRAY_SIZE );


    return 0;
}


Stack* test_ctor ( int sz )
{
    Stack* st = stack_ctor ( sz );

    if ( st == NULL )
    {
        printf ( "No stack - no work.\n" );

        exit ( -1 );
    }

    return st;
}


void test_push ( Stack* st, int* arr, int num )
{
    int i = 0;

    for ( i = 0; i < num; i++ )
    {
        printf ( "test_push: element %4d pushed\n", arr[i] );

        push_st ( st, arr[i] );
    }


    printf ( "\n\n" );

}


void test_pop ( Stack* st, int num )
{
    int i = 0;
    int k = 0;

    int ok = 0;

    for ( i = 0; i < num; i++ )
    {
        printf ( "test_pop: %4d time: ", i + 1 );

        k = pop_st ( st );

        ok = ok_st ( st );

        if ( ok == S_ERR_EMPTY_STACK ) printf ( "I can't pop anything :( Error %d\n", ok );

        else
        {
            printf ( "%4d\n", k );
        }
    }
}
