/**
*   Vector data container.
*
*   @file main.cpp
*
*   @date 05.2015
*
*   @copyright GNU GPL v2.0
*
*   @author Viktor Prutyanov mailto:vitteran@gmail.com
*/

#include <stdio.h>
#include <exception>

template <typename T>
class Vector
{
public:
	Vector();
	Vector(const Vector<T>& vector);
	Vector(size_t size, const T& value);
    
	~Vector();

	void dump();

    T& operator[](size_t pos);
    T& at(size_t pos);

	size_t capacity();
	size_t size();
private:
	size_t v_capacity;
	size_t v_size;
	T *v_data;
};

template <typename T>
Vector<T>::Vector()
	: v_size(0), v_capacity(1), v_data(new T[1])
{
	//Nothing to do
}

template <typename T>
Vector<T>::Vector(const Vector<T>& vector)
	: v_size(vector.v_size), v_capacity(vector.v_capacity), v_data(new T[v_size])
{
	for (size_t i = 0; i < v_size; i++)
	{
		v_data[i] = vector.v_data[i];
	}
}

template <typename T>
Vector<T>::Vector(size_t size, const T& value)
	: v_size(size), v_capacity(size), v_data(new T[size])
{
	for (size_t i = 0; i < v_size; i++)
	{
		v_data[i] = value;
	}
}

template <typename T>
void Vector<T>::dump()
{
    printf("Vector at 0x%X. Size is %d, capacity is %d.\n", this, v_size, v_capacity);
	if (v_size == 0) return;
	for (size_t i = 0; i < v_size; i++)
	{
		printf("%d [0x%X] %4d\n", i, (v_data + i), v_data[i]);
	}
}

template <typename T>
T& Vector<T>::at(size_t pos)
{
    if (pos < v_size)
    {
        return v_data[pos];
    }
    else
    {
        throw std::out_of_range("Array index out of bounds.");
    }
}

template <typename T>
T& Vector<T>::operator[](size_t pos)
{
    return v_data[pos];
}

template <typename T>
Vector<T>::~Vector()
{
	delete[] v_data;
}