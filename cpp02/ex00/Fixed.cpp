#include "Fixed.hpp"
#include <iostream>

const int Fixed::_frac_bit = 8;

Fixed::Fixed()
  : _fixed(0)
{
  std::cout << "Default constructor called\n";
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& f)
  : _fixed(f._fixed)
{
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

Fixed& Fixed::operator=(const Fixed& f) {
  std::cout << "Copy assignment operator called\n";
  if (this == &f) {
    return *this;
  }
  _fixed = f._fixed;
  return *this;
}