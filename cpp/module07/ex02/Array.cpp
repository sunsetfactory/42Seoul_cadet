#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(Array const &src) : _array(new T[src._size]), _size(src._size)
{
    for (unsigned int i = 0; i < _size; i++)
    {
        _array[i] = src._array[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &rhs)
{
    if (this != &rhs)
    {
        if (_array)
            delete[] _array;
        _array = new T[rhs._size];
        _size = rhs._size;
        for (unsigned int i = 0; i < _size; i++)
        {
            _array[i] = rhs._array[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    if (_array)
        delete[] _array;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
}
