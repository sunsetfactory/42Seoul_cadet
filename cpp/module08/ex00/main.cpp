#include <vector>

#include "easyfind.hpp"

int main() {
  std::vector<int> vec;
  vec.push_back(4);
  vec.push_back(5);
  vec.push_back(6);
  vec.push_back(7);
  vec.push_back(8);
  try {
    std::vector<int>::iterator it = easyfind(vec, 4);
    std::cout << "Value found at index: " << std::distance(vec.begin(), it) << std::endl;
  } catch (const std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  return 0;
}
