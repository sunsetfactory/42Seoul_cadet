#include "whatever.hpp"

int main()
{
  int a = 2;
  int b = 3;
  std::cout << "int swap(a, b)\n\n";
  std::cout << "=====before====\n";
  std::cout << "a = " << a << ", b = " << b << "\n";
  swap(a, b);
  std::cout << "=====after=====\n";
  std::cout << "a = " << a << ", b = " << b << "\n";
  std::cout << "\n";
  std::cout << "min(a, b) = " << ::min(a, b) << "\n";
  std::cout << "max(a, b) = " << ::max(a, b) << "\n";
  std::cout << "\n\n";

  std::string c = "42";
  std::string d = "seoul";
  std::cout << "string swap(c, d)\n";
  std::cout << "=====before====\n";
  std::cout << "c = " << c << ", d = " << d << "\n";
  swap(c, d);
  std::cout << "=====after=====\n";
  std::cout << "c = " << c << ", d = " << d << "\n";
  std::cout << "\n";
  std::cout << "min(c, d) = " << ::min(c, d) << "\n";
  std::cout << "max(c, d) = " << ::max(c, d) << "\n";

  return 0;
}
