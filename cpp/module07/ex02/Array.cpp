#include "Array.hpp"

template <typename T>
Array<T>::Array() : _length(0), array(new T[0]) {}

template <typename T>
Array<T>::Array(Array const &src)
    : _length(src._length), array(new T[src._length]) {
  for (int i = 0; i < src._length; i++) {
    array[i] = src.array[i];
  }
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &rhs) {
  if (this != &rhs) {
    delete[] array;
    _length = rhs._length;
    array = new T[rhs._length];
    for (int i = 0; i < rhs._length; i++) {
      array[i] = rhs.array[i];
    }
  }
  return *this;
}

template <typename T>
Array<T>::~Array() {
  delete[] array;
}

template <typename T>
Array<T>::Array(unsigned int n) : _length(n), array(new T[n]) {}

template <typename T>
T &Array<T>::operator[](unsigned int i) {
  if (i >= _length) {
    throw OutOfLimitsException();
  }
  return array[i];
}

template <typename T>
int Array<T>::size() const {
  return _length;
}

template <typename T>
const char *Array<T>::OutOfLimitsException::what() const {
  return "Out of limits";
}

template <typename T>
const char *Array<T>::EmptyArrayException::what() const {
  return "Empty array";
}
