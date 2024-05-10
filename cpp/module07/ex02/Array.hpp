#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

// C++에서 템플릿 클래스의 멤버 함수를 구현할 때, 일반적으로 헤더 파일(.hpp)에
// 직접 구현합니다. 이는 템플릿이 컴파일 시점에 구체화되기 때문입니다. 즉,
// 컴파일러는 템플릿 클래스를 사용하는 모든 코드를 보고 해당 템플릿을 구체화해야
// 합니다. 그러므로 템플릿 클래스의 구현은 헤더 파일에 포함해야 합니다.

// throw()는 C++98에서 예외 사양을 지정하는 데 사용되었지만, C++11에서는
// noexcept 키워드로 대체되었습니다. noexcept 키워드는 예외 사양을 지정하는 데
// 더 명확하고 간결하게 사용할 수 있습니다.

// noexcept 키워드는 함수가 예외를 던지지 않음을 나타내며, throw()와 달리
// 예외 사양을 지정하지 않는 함수도 noexcept 키워드를 사용할 수 있습니다.
// noexcept 키워드는 컴파일러에게 함수가 예외를 던지지 않음을 알려주므로
// 컴파일러는 예외 처리 코드를 생성하지 않아 더 효율적인 코드를 생성할 수
// 있습니다.

// noexcept 키워드는 함수가 예외를 던지지 않음을 보장하지만, noexcept 키워드가
// 지정된 함수가 다른 noexcept 키워드가 지정되지 않은 함수를 호출할 때, 호출된
// 함수가 예외를 던질 수 있습니다. 이러한 경우, 호출된 함수가 예외를 던지면
// std::terminate()가 호출되어 프로그램이 종료됩니다.

template <typename T>
class Array {
 private:
  T *_array;
  unsigned int _size;

 public:
  Array() : _array(NULL), _size(0) {
    // empty function body
  }
  Array(Array const &src) : _array(new T[src.size()]), _size(src.size()) {
    for (unsigned int i = 0; i < _size; i++) {
      _array[i] = src._array[i];
    }
  }
  Array &operator=(Array const &rhs) {
    if (this != &rhs) {
      if (_array) {
        delete[] _array;
      }
      _array = new T[rhs.size()];
      _size = rhs.size();
      for (unsigned int i = 0; i < _size; i++) {
        _array[i] = rhs._array[i];
      }
    }
    return *this;
  }
  ~Array() {
    if (_array) {
      delete[] _array;
    }
  }

  Array(unsigned int n) {
    _array = new T[n];
    _size = n;
  }

  T &operator[](unsigned int i) {
    if (i >= _size) {
      throw OutOfRangeException();
    }
    return _array[i];
  }
  unsigned int size() const {
    // empty function body
    return _size;
  }

  class OutOfRangeException : public std::exception {
    virtual const char *what() const throw() {
      // empty function body
      return "Index out of range";
    }
  };
};

#endif