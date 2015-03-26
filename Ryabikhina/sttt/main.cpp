#include <iostream>
#include <stdio.h>
#include <assert.h>
#include "stack.h"

using namespace std;

int main()
{
    stack s(5);

    for ( int i = 1; i <= 11; i++ )
    {
        s.push(i);
        printf ( "test_push: element %4d pushed\n", i );
    }

    s.dump();


    for ( int i = 0; i < 10; i++ )
    {
        printf ( "test_pop: %4d time: ", i + 1 );
        int k = s.pop ( );
        printf ( "%4d\n", k );
    }

    int y = s.top ( );
    int k = s.pop ( );
    printf ( "%4d %d\n", k, y );


    return 0;
}
