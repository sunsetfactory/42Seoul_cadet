#include "span.hpp"

int main() {
  Span sp = Span(5);

  sp.addNumber(-2);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(2147483647);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

  // Span sp2 = Span(10000);
  // std::vector<int> v(10000, 0);
  // // 1~10000
  // for (int i = 0; i < 10000; i++) {
  //   v[i] = i;
  // }
  // sp2.addNumber(v.begin(), v.end());
  // sp2.printNumbers();
}