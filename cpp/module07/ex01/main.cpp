#include "iter.hpp"

template <typename T>
void print(T const &x)
{
  std::cout << x << std::endl;
}

int main(void)
{
  int intArray[] = {1, 2, 3, 4, 5};
  float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
  std::string stringArray[] = {"one", "two", "three", "four", "five"};

  std::cout << "Int array:" << std::endl;
  iter(intArray, 5, print);
  std::cout << "Float array:" << std::endl;
  iter(floatArray, 5, print);
  std::cout << "String array:" << std::endl;
  iter(stringArray, 5, print);
  return 0;
}