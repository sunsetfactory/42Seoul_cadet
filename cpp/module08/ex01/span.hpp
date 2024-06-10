#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>

class Span {
 private:
  std::vector<int> numbers;
  unsigned int capacity;

  // unused private constructor and assignment operator
  Span();
  Span& operator=(Span const& rhs);

 public:
  Span(Span const& src);
  ~Span();

  Span(unsigned int N);

  void addNumber(int number);
  void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
  int shortestSpan();
  int longestSpan();
};

#endif