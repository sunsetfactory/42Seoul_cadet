#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array
{
  public:
    Array();
    Array(Array const &src);
    Array &operator=(Array const &rhs);
    ~Array();

    Array(unsigned int n);

    T &operator[](unsigned int i)
    {
        if (i >= _size)
            throw std::out_of_range("Index out of range");
        return _array[i];
    }

    unsigned int size() const
    {
        return _size;
    }
};

#endif