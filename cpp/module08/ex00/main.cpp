#include <vector>

#include "easyfind.hpp"

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5};
  try {
    auto it = easyfind(vec, 3);
    std::cout << "Value found at index: " << std::distance(vec.begin(), it)
              << std::endl;
  } catch (const std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  return 0;
}