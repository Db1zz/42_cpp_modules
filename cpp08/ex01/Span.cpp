#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <functional>
#include <limits.h>

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

void Span::PushBack(const std::vector<int> &numbers) {
  if (numbers.size() + numbers_.size() > numbers_.capacity()) {
    throw NotEnoughSpace();
  }
  std::copy(numbers.begin(), numbers.end(), std::back_inserter(numbers_));
}

Span::VecIntIt Span::Begin() const {
  return numbers_.begin();
}

Span::VecIntIt Span::End() const {
  return numbers_.end();
}

void Span::PrintVector() {
  for (size_t i = 0; i < numbers_.size(); i++) {
    std::cout << numbers_[i] << ", ";
  }
  std::cout << std::endl;
}

const char *Span::NotEnoughSpace::what() const throw() {
  return "Not enough space in the array to add the number";
}

const char *Span::ArrayTooSmall::what() const throw() {
  return "There's not enough numbers to calculate range between them";
}

int Span::ShortestSpan() {
  if (numbers_.size() < 2) {
    throw ArrayTooSmall();
  }

  std::sort(numbers_.begin(), numbers_.end());
  int shortest = INT_MAX;

  for (size_t i = 0; i + 1 < numbers_.size(); ++i) {
    int span = numbers_[i + 1] - numbers_[i];
    if (span < shortest) {
      shortest = span; 
    }
  }
  return shortest;
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
