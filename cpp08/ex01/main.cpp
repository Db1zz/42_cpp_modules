#include "Span.hpp"
#include <vector>
#include <iostream>

int main()
{
  Span span(5);

  span.AddNumber(3);
  span.AddNumber(4);
  span.AddNumber(-2);
  span.AddNumber(5);
  span.AddNumber(-1);

  std::cout << span.ShortestSpan() << std::endl;
  std::cout << span.LongestSpan() << std::endl;
  return 0;
}