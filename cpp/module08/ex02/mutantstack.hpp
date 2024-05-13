#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <iostream>
#include <list>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 private:
  MutantStack(const MutantStack& other);
  MutantStack& operator=(const MutantStack& other);

 public:
  MutantStack() : std::stack<T>(){};
  virtual ~MutantStack(){};  // virtual 소멸자

  // typedef는 복잡한 타입을 간단하게 표현하기 위해 사용
  // typename은 템플릿 타입을 나타내는 키워드
  // typename과 typename <T>의 차이는 typename은 템플릿 클래스 내부에서 사용되는
  // 타입을 나타내고 typename <T>는 템플릿 클래스 외부에서 사용되는 타입을
  // 나타냄 deque 는 stack 의 기본 container deque<T>는 T 타입의 요소를 저장하는
  // deque::iterator는 deque<T>의 iterator 타입을 나타냄
  typedef typename std::deque<T>::iterator iterator;

  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }

  typedef typename std::deque<T>::const_iterator const_iterator;

  const_iterator begin() const { return this->c.begin(); }
  const_iterator end() const { return this->c.end(); }

  // reverse_iterator란 iterator를 역순으로 순회하는 것
  typedef typename std::deque<T>::reverse_iterator reverse_iterator;

  // rbegin은 deque의 마지막 요소를 가리키는 iterator를 반환
  // rend는 deque의 첫번째 요소를 가리키는 iterator를 반환
  reverse_iterator rbegin() { return this->c.rbegin(); }
  reverse_iterator rend() { return this->c.rend(); }

  typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

  const_reverse_iterator rbegin() const { return this->c.rbegin(); }
  const_reverse_iterator rend() const { return this->c.rend(); }

  typedef typename std::deque<T>::size_type size_type;
};

#endif