#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
  Fixed();
  Fixed(float value);
  Fixed(const Fixed& f);
  ~Fixed();
  
  void setRawBits(int fixed);
  int getRawBits() const;
  float toFloat() const;
  int toInt() const;
  static Fixed& min(Fixed& a, Fixed& b);
  static const Fixed& min(const Fixed& a, const Fixed& b);
  static Fixed& max(Fixed& a, Fixed& b);
  static const Fixed& max(const Fixed& a, const Fixed& b);

  Fixed& operator=(const Fixed& f);
  bool operator>(const Fixed& value) const;
  bool operator<(const Fixed& value) const;
  bool operator>=(const Fixed& value) const;
  bool operator<=(const Fixed& value) const;
  bool operator==(const Fixed& value) const;
  bool operator!=(const Fixed& value) const;
  Fixed operator+(const Fixed& value) const;
  Fixed operator-(const Fixed& value) const;
  Fixed operator*(const Fixed& value) const;
  Fixed operator/(const Fixed& value) const;
  Fixed& operator++();
  Fixed operator++(int);
  Fixed& operator--();
  Fixed operator--(int);

private:
  int float_to_fixed(float value) const;
  float fixed_to_float(int value) const;

  int _fixed;
  static const int _frac_bit;
};

std::ostream& operator<<(std::ostream& os, const Fixed& c);

#endif  // FIXED_HPP