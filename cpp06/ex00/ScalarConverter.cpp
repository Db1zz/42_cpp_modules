#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <limits.h>
#include <float.h>
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


void ScalarConverter::display_double_to_float(double d) {
  std::cout << "float: ";
  if (d > FLT_MAX || d < FLT_MIN) {
    std::cout << "Overflow\n";
  }
  // } else if (d > INT_MAX || d < INT_MIN) {
  //   std::cout << "Imposible\n";
  // }
  else {
    std::cout << std::fixed << static_cast<float>(d) << "f\n";
  }
}

void ScalarConverter::display_double(double d) {
  std::cout << "double: ";
  // if (d > ULLONG_MAX || d < LLONG_MIN) {
  //   std::cout << "Impossible\n";
  // } else {
    std::cout << std::fixed << d << '\n';
  // }
}

void ScalarConverter::Convert(const std::string &literal) {
  double d = atof(literal.c_str());

  std::cout.precision(2);
  if (d - static_cast<long long int>(d) == 0) {
    std::cout.precision(1);
  }

  display_double_to_char(d);
  display_double_to_int(d);
  display_double_to_float(d);
  display_double(d);
}
