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
  using std::stack<T>::c;

  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef typename std::stack<T>::container_type::const_iterator const_iterator;

  iterator begin() {
    // empty() is a member function of std::deque
    return c.begin();
  }
  iterator end() {
    // empty() is a member function of std::deque
    return c.end();
  }

  const_iterator begin() const {
    // empty() is a member function of std::deque
    return c.begin();
  }
  const_iterator end() const {
    // empty() is a member function of std::deque
    return c.end();
  }
};

#endif