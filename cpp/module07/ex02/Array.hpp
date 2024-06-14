#ifndef Array_hpp
#define Array_hpp
#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
class Array
{
private:
  T *_array;
  unsigned int _size;

public:
  Array() : _array(NULL), _size(0)
  {
    // empty function body
  }
  Array(Array const &src) : _array(new T[src.size()]), _size(src.size())
  {
    for (unsigned int i = 0; i < _size; i++)
    {
      _array[i] = src._array[i];
    }
  }
  Array &operator=(Array const &rhs)
  {
    if (this != &rhs)
    {
      if (_array)
      {
        delete[] _array;
      }
      _array = new T[rhs.size()];
      _size = rhs.size();
      for (unsigned int i = 0; i < _size; i++)
      {
        _array[i] = rhs._array[i];
      }
    }
    return *this;
  }
  ~Array()
  {
    if (_array)
    {
      delete[] _array;
    }
  }

  Array(unsigned int n)
  {
    _array = new T[n];
    _size = n;
  }

  T &operator[](unsigned int i)
  {
    if (i >= _size)
    {
      throw OutOfRangeException();
    }
    return _array[i];
  }

  const T &operator[](unsigned int i) const
  {
    if (i >= _size)
    {
      throw OutOfRangeException();
    }
    return _array[i];
  }

  unsigned int size() const
  {
    // empty function body
    return _size;
  }

  class OutOfRangeException : public std::exception
  {
    virtual const char *what() const throw()
    {
      // empty function body
      return "Index out of range";
    }
  };

  void printArray() const
  {
    for (unsigned int i = 0; i < _size; i++)
    {
      std::cout << i << " : " << _array[i] << "\n";
    }
    std::cout << std::endl;
  }
};

#endif