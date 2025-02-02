#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <limits.h>

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

  std::cout << "char: ";
  if (!is_normal_double(d)) {
    std::cout << "impossible\n";
  } else if (!is_visible_char(c)) {
    std::cout << "Non displayable\n";
  } else {
    std::cout << '\'' << c << "\'\n";
  }
}

/*
  TODO: add check for INTMAX and INTMIN
*/
void ScalarConverter::display_double_to_int(double d) {
  int i = static_cast<int>(d);

  std::cout << "int: ";
  if (!is_normal_double(d)) {
    std::cout << "impossible\n";
  } else {
    std::cout << i << '\n';
  }
}

void ScalarConverter::display_double_float(double d) {
  std::string point_zero = "";
  int i = static_cast<int>(d);
  if (!(d - i > 0 || d - i < 0) && is_normal_double(d)) {
    point_zero = ".0";
  }
  std::cout << "float: " << static_cast<float>(d) << point_zero << "f\n";
  std::cout << "double: " << d << point_zero << '\n';
}

void ScalarConverter::Convert(const std::string &literal) {
  double d = atof(literal.c_str());

  display_double_to_char(d);
  display_double_to_int(d);
  display_double_float(d);
}
