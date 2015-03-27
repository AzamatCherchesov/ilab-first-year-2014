/**
*   Vector data container. Vector test.
*
*   @file main.cpp
*
*   @date 05.2015
*
*   @copyright GNU GPL v2.0
*
*   @author Viktor Prutyanov mailto:vitteran@gmail.com
*/

#include "vector.h"
#include <iostream>

int main()
{
    Vector<int> vector1;
    vector1.dump();
	Vector<int> vector2(3, 2);
	vector2.dump();
	Vector<int> vector3(vector2);
	vector3.dump();

    printf("%d -> ", vector2.at(2));
    vector2.at(2) = 8;
    printf("%d\n", vector2.at(2));
    vector2.dump();
    vector2[2] = 2;
    vector2.dump();

    printf("Try to access 3rd element of array: ");
    try
    {
        printf("%d\n", vector2.at(3)); 
    }
    catch (const std::out_of_range& e)
    {
        printf(e.what());
        printf("\n");
    }

	#ifdef _DEBUG
		system("pause");
	#endif

	return EXIT_SUCCESS;
}