#ifndef whatever_hpp
#define whatever_hpp
#include <iostream>
#include <string>

template <typename T> void swap(T &a, T &b)
{
    T c;

    c = a;
    a = b;
    b = c;
}

template <typename T> const T &min(const T &a, const T &b)
{
    return a < b ? a : b;
}

template <typename T> const T &max(const T &a, const T &b)
{
    return a >= b ? a : b;
}

#endif
