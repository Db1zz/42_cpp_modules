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
  _fixed = float_to_fixed(value);
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
  return fixed_to_float(_fixed);
}

int Fixed::toInt() const {
  return fixed_to_float(_fixed);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
  if (a < b)
    return a;
  else
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
  if (a < b)
    return a;
  else
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
  if (a > b)
    return a;
  else
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
  if (a > b)
    return a;
  else
    return b;
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

bool Fixed::operator>(const Fixed& value) const {
  return _fixed > value._fixed;
}

bool Fixed::operator<(const Fixed& value) const {
  return _fixed < value._fixed;
}

bool Fixed::operator>=(const Fixed& value) const {
  return _fixed >= value._fixed;
}

bool Fixed::operator<=(const Fixed& value) const {
  return _fixed <= value._fixed;
}

bool Fixed::operator==(const Fixed& value) const {
  return _fixed == value._fixed;
}

bool Fixed::operator!=(const Fixed& value) const {
  return _fixed != value._fixed;
}

Fixed Fixed::operator+(const Fixed& value) const {
  return this->toFloat() + value.toFloat();
}

Fixed Fixed::operator-(const Fixed& value) const {
  return this->toFloat() - value.toFloat();
}

Fixed Fixed::operator*(const Fixed& value) const {
  return this->toFloat() * value.toFloat();
}

Fixed Fixed::operator/(const Fixed& value) const {
  return this->toFloat() / value.toFloat();
}

Fixed& Fixed::operator++() {
  _fixed = float_to_fixed((fixed_to_float(_fixed) + 1));
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);

  _fixed = float_to_fixed((fixed_to_float(_fixed) + 1));
  return tmp;
}

Fixed& Fixed::operator--() {
  _fixed = float_to_fixed((fixed_to_float(_fixed) - 1));
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);

  _fixed = float_to_fixed((fixed_to_float(_fixed) - 1));
  return tmp;
}

int Fixed::float_to_fixed(float value) const {
  return roundf(value * (1 << _frac_bit));
}

float Fixed::fixed_to_float(int value) const {
  return (float)value / (1 << _frac_bit);
}