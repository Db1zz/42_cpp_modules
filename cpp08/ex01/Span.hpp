#ifndef SPAN_HPP
# define SPAN_HPP

#include <stdint.h>
#include <vector>
#include <exception>

class Span {
public:
  Span(uint32_t capacity = 0);
  Span(const Span &copy);
  ~Span();
  Span &operator=(const Span &copy);

  void AddNumber(int number);

  class NotEnoughSpace : public std::exception {
  public:
    const char *what() const throw();
  };

  int ShortestSpan() const;
  int LongestSpan() const;

private:
  uint32_t capacity_;
  uint32_t size_;
  std::vector<int> numbers_;
  int smallest_;
  int biggest_;
};

#endif  // SPAN_HPP