#include "Span.hpp"
#include <vector>
#include <iostream>

std::vector<int> &operator<<(std::vector<int> &v, const int &value) {
  v.push_back(value);
  return v;
}

std::vector<int> &operator,(std::vector<int> &v, const int &value) {
  v.push_back(value);
  return v;  
}

int main()
{
  std::vector<int> numbers;
  numbers.reserve(750);
  
  numbers << 99, 3, 97, 0, -1;

  Span span(500);
  span.PushBack(numbers);

  std::cout << span.ShortestSpan() << std::endl;
  std::cout << span.LongestSpan() << std::endl;
  return 0;
}