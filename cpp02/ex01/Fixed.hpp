#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
  Fixed();
  Fixed(float value);
  Fixed(const Fixed& f);
  ~Fixed();
  
  void setRawBits(int const fixed);
  int getRawBits() const;
  float toFloat() const;
  int toInt() const;
  Fixed& operator=(const Fixed& f);
  friend std::ostream& operator<<(std::ostream& os, const Fixed& c);
private:
  int _fixed;
  static const int _frac_bit;
};

#endif  // FIXED_HPP