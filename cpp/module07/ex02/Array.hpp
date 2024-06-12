#ifndef Array_hpp
#define Array_hpp
#include <iostream>

template <typename T>
class Array {
 private:
  int _length;

 public:
  T *array;

  Array();
  Array(Array const &src);
  Array &operator=(Array const &rhs);
  ~Array();

  Array(unsigned int n);

  T &operator[](unsigned int i);
  int size() const;

  class OutOfLimitsException {
   public:
    virtual const char *what() const;
  };

  class EmptyArrayException {
   public:
    virtual const char *what() const;
  };
};

#endif