#ifndef SPAN_HPP
# define SPAN_HPP

#include <stdint.h>
#include <vector>
#include <exception>
#include <iterator>
#include <ostream>

class Span {
public:
  Span(uint32_t capacity = 0);
  Span(const Span &copy);
  ~Span();
  Span &operator=(const Span &copy);

  typedef std::vector<int>::const_iterator VecIntIt;

  void AddNumber(int number);
  void PushBack(const std::vector<int> &numbers);

  VecIntIt Begin() const;
  VecIntIt End() const;

  void PrintVector();
  
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