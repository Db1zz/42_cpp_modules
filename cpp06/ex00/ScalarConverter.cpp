#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <limits.h>
#include <sstream>

bool ScalarConverter::is_normal_double(double val) {
  if (val == INFINITY) {
    return false;
  } else if (val == -INFINITY) {
    return false;
  } else if (val != val) {
    return false;
  }
  return true;
}

bool ScalarConverter::is_visible_char(char c) {
  return (c >= 33 && c <= 126);
}

void ScalarConverter::display_double_to_char(double d) {
  char c = static_cast<char>(d);
  int i = static_cast<int>(d);

  std::cout << "char: ";
  if (!is_normal_double(d)) {
    std::cout << "Impossible\n";
  } else if (i < CHAR_MIN || i > CHAR_MAX) {
    std::cout << "Overflow\n";
  } else if (!is_visible_char(c)) {
    std::cout << "Non displayable\n";
  } else {
    std::cout << '\'' << c << "\'\n";
  }
}

void ScalarConverter::display_double_to_int(double d) {
  int i = static_cast<int>(d);

  std::cout << "int: ";
  if (!is_normal_double(d)) {
    std::cout << "Impossible\n";
  } else if (d < INT_MIN || d > INT_MAX) {
    std::cout << "Overflow\n";
  } else {
    std::cout << i << '\n';
  }
}

/*
  Mantisa mask:
  0000 0000 0111 1111 1111 1111 1111 1111 or 8,388,607
  SEEE EEEE EMMM MMMM MMMM MMMM MMMM MMMM
*/

typedef unsigned long int uint64_t;

int ScalarConverter::extract_precision(double val) {
  static const uint64_t sign_mask = (1ULL << 63);
  static const uint64_t exponent_mask = ((1ULL << 11) - 1) << 52;
  static const uint64_t mantissa_mask = (1ULL << 52) - 1;

  union {double d; uint64_t i;} value;
  value.d = val;

  /*
    TODO
  */
  uint64_t sign_bits = (sign_mask & value.i) >> 63;
  uint64_t exponent_bits = ((exponent_mask & value.i) << 1) >> 53;
  uint64_t mantisa_bits = ((mantissa_mask & value.i) << 12) >> 12;

  return val;
}

void ScalarConverter::display_double_float(double d) {
  std::cout << "float: " << static_cast<float>(d) << "f\n";
  std::cout << "double: " << d  << '\n';
}

void ScalarConverter::Convert(const std::string &literal) {
  double d = atof(literal.c_str());
  display_double_to_char(d);
  display_double_to_int(d);
  display_double_float(d);
}
