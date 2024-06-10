#include "span.hpp"

Span::Span(Span const& src) : capacity(src.capacity) { numbers = src.numbers; }

Span::~Span() {}

Span::Span(unsigned int N) : capacity(N) {}

void Span::addNumber(int number) {
  if (numbers.size() >= capacity) {
    throw std::runtime_error("Cannot add more numbers. Capacity reached.");
  }
  numbers.push_back(number);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
  if (numbers.size() + std::distance(begin, end) > capacity) {
    throw std::runtime_error("Cannot add more numbers. Capacity reached.");
  }
  numbers.insert(numbers.end(), begin, end);
}

int Span::shortestSpan() {
  if (numbers.size() <= 1) {
    throw std::runtime_error("Not enough numbers to find span.");
  }
  std::sort(numbers.begin(), numbers.end());
  int shortest = numbers[1] - numbers[0];
  for (size_t i = 2; i < numbers.size(); i++) {
    int span = numbers[i] - numbers[i - 1];
    if (span < shortest) {
      shortest = span;
    }
  }
  return shortest;
}

int Span::longestSpan() {
  if (numbers.size() <= 1) {
    throw std::runtime_error("Not enough numbers to find span.");
  }
  std::sort(numbers.begin(), numbers.end());
  return numbers.back() - numbers.front();
}
