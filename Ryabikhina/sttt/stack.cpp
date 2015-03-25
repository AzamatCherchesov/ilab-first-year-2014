#include "stack.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>

//ctor
stack::stack( int size)
{
    count = 0;
    this -> size = size;
    data = new int [size ];// выделяем память из интов размера size
    //you should check a lot here ))
}

void stack:: push(int num)
{
    assert ( is_ok() );
    if ( count < size )
    {
        data[count] = num;
        count++;
    }
    else
    {
        data = (int*) realloc ( data, 2*size*sizeof (int));
        size = size*2;
        data[count] = num;
        count++;
    }
}

int stack:: pop()
{
    assert ( is_ok() );
    int temp = data[count-1];
    count--;
    assert(is_ok() );
    return temp;
}

bool stack::is_ok()
{
    if (count > size)  return false;
    if ( data == NULL) return false;
    if ( ( count < 0 ) || ( size <= 0 )) return false;
    return true;
}

int stack:: top ()
{
    assert ( is_ok() );
    return data [ count - 1 ];
}

void stack::dump()
{
    printf ( "--dump-st-- \n" );
    int i = 0;
    for ( i = 0; i < count; i++ )
    {
        printf ( "--dump-st-- data[%4d] = %10d\n", i, data [ i ] );
    }
    printf ( "--dump-st-- Stack properties: size = %4d, counter = %4d\n\n\n",
             size, count );
}

//dtor
stack::~stack()
{
    delete [ ] data ;
    count = -3000;
    size = -2000;
}


