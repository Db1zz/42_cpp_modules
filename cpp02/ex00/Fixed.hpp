#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
public:
  Fixed();
  Fixed(const Fixed& f);
  ~Fixed();
  
  void setRawBits(int const fixed);
  int getRawBits() const;
  Fixed& operator=(const Fixed& f);
private:
  int _fixed;
  static const int _frac_bit;
};

#endif  // FIXED_HPP