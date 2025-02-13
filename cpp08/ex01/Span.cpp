#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <functional>

Span::Span(uint32_t capacity)
{
  numbers_.reserve(capacity);
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
  return *this;
}

void Span::AddNumber(int number) {
  if (numbers_.size() == numbers_.capacity()) {
    throw NotEnoughSpace();
  }
  numbers_.push_back(number);
}

const char *Span::NotEnoughSpace::what() const throw() {
  return "Not enough space in the array to add the number";
}

void print_vector(const std::vector<int> &v) {
  std::cout << "Size: " << v.size() << std::endl;
  for (size_t i = 0; i < v.size(); i++) {
    std::cout << v[i] << ", ";
  }
  std::cout << std::endl;
}

const char *Span::ArrayTooSmall::what() const throw() {
  return "There's not enough numbers to calculate range between them";
}

int Span::ShortestSpan() {
  if (numbers_.size() < 2) {
    throw ArrayTooSmall();
  }

  std::nth_element(numbers_.begin(), numbers_.begin() + 1, numbers_.end(), std::greater<int>());
  return numbers_[numbers_.size() - 2] - numbers_[numbers_.size() - 1];
}

int Span::LongestSpan() const {
  VecIntIt max_it;
  VecIntIt min_it;

  if (numbers_.size() < 2) {
    throw ArrayTooSmall();
  }

  max_it = std::max_element(numbers_.begin(), numbers_.end());
  min_it = std::min_element(numbers_.begin(), numbers_.end());
  return *max_it - *min_it;
}
