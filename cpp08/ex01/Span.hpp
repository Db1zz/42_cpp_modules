#ifndef SPAN_HPP
# define SPAN_HPP

#include <stdint.h>
#include <vector>
#include <exception>
#include <iterator>

class Span {
public:
  Span(uint32_t capacity = 0);
  Span(const Span &copy);
  ~Span();
  Span &operator=(const Span &copy);

  void AddNumber(int number);
  void AddNumber();

  class NotEnoughSpace : public std::exception {
  public:
    const char *what() const throw();
  };

  class ArrayTooSmall : public std::exception {
  public:
    const char *what() const throw();
  };

  int ShortestSpan();
  int LongestSpan() const;

private:
  std::vector<int> numbers_;
};

#endif  // SPAN_HPP