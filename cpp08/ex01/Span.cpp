#include "Span.hpp"
#include <iostream>
#include <algorithm>

Span::Span(uint32_t capacity)
  : capacity_(capacity), numbers_(capacity)
{
  std::cout << "Span default constructor called\n";
}

Span::Span(const Span &copy)
{
  std::cout << "Span copy constructor called\n";
  *this = copy;
}

Span::~Span() {
  std::cout << "Span destructor called\n";
}

Span &Span::operator=(const Span &copy) {
  if (this == &copy) {
    return *this;
  }
  std::cout << "Span copy assignment called\n";
  numbers_ = copy.numbers_;
  capacity_ = copy.capacity_;
  size_ = copy.size_;
  return *this;
}

void Span::AddNumber(int number) {
  if (size_ == capacity_) {
    throw NotEnoughSpace();
  }
  size_++;
  numbers_.push_back(number);
  if (number < smallest_) {
    smallest_ = number;
  } else if (number > biggest_) {
    biggest_ = number;
  }
}

const char *Span::NotEnoughSpace::what() const throw() {
  return "Not enough space in the array to add the number";
}

int Span::ShortestSpan() const {

}

int Span::LongestSpan() const {

}
