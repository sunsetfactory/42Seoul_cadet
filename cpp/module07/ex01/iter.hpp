#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T1, typename T2>
void iter(T1 *array, size_t size, void (*f)(T2 &))
{
    for (size_t i = 0; i < size; i++)
    {
        f(array[i]);
    }
}

#endif