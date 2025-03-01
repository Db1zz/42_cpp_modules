#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_frac_bit = 8;

Fixed::Fixed()
  : _fixed(0)
{
  std::cout << "Default constructor called\n";
}

Fixed::Fixed(float value) {
  std::cout << "Float constructor called\n";
  _fixed = roundf(value * (1 << _frac_bit));
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& f)
{
  *this = f;
  std::cout << "Copy constructor called\n";
}

void Fixed::setRawBits(int const fixed) {
  std::cout << "setRawBits member function called\n";
  _fixed = fixed;
}

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called\n";
  return _fixed;
}

float Fixed::toFloat() const {
  return static_cast<float>(_fixed) / (1 << _frac_bit);
}

int Fixed::toInt() const {
  return (_fixed / (1 << _frac_bit));
}

Fixed& Fixed::operator=(const Fixed& f) {
  std::cout << "Copy assignment operator called\n";
  if (this == &f) {
    return *this;
  }
  _fixed = f._fixed;
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& c) {
  return os << c.toFloat();
}