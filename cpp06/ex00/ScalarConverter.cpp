#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <limits.h>
#include <float.h>

bool ScalarConverter::DotChecker(int i, const std::string &input, bool dot_found, bool exp_found) {
  if (dot_found) {
    return false;
  }
  dot_found = true;
  if (isdigit(input[i + 1])) {
    return DecimalChecker(i + 1, input, true, exp_found);
  }
  return false;
}

bool ScalarConverter::DecimalChecker(int i, const std::string &input, bool dot_found, bool exp_found) {
  while (isdigit(input[i])) {
    i++;
  }
  if (!exp_found && !dot_found && input[i] == '.') {
    return DotChecker(i, input, dot_found, exp_found);
  } else if (!exp_found && std::tolower(input[i]) == 'e') {
    return ExponentChecker(i, input, dot_found, exp_found);
  } else if ((input[i] == 'f' && input[i + 1] == '\0') || input[i] == '\0') {
    return true;
  }
  return false;
}

bool ScalarConverter::ExponentChecker(int i, const std::string &input, bool dot_found, bool exp_found) {
  if (exp_found) {
    return false;
  }
  exp_found = true;
  if (input[i + 1] == '+' || input[i + 1] == '-') {
    i++;
  }
  if (isdigit(input[i + 1])) {
    return DecimalChecker(i + 1, input, dot_found, exp_found);
  }
  return false;
}

/*
  TODO: add handlers for char, inf nan and etc, default float
*/
// 1.23123e123 1.7976931348623157e+308
bool ScalarConverter::IsInputValid(const std::string &input) {  
  if (input.size() == 1 && !isdigit(input[0])) {
    return true;
  }

  int i = 0;
  if (input[i] == '-' || input[i] == '+') {
    i++;
  }
  if (isdigit(input[i])) {
    return DecimalChecker(i, input, false, false);
  }
  return false;
}

bool ScalarConverter::IsNormalDouble(double val) {
  if (val == INFINITY) {
    return false;
  } else if (val == -INFINITY) {
    return false;
  } else if (val != val) {
    return false;
  }
  return true;
}

bool ScalarConverter::IsVisibleChar(char c) {
  return (c >= 33 && c <= 126);
}

void ScalarConverter::DisplayDoubleToChar(double d) {
  char c = static_cast<char>(d);
  int i = static_cast<int>(d);

  std::cout << "char: ";
  if ((i < CHAR_MIN || i > CHAR_MAX) || !IsNormalDouble(d)) {
    std::cout << "Impossible\n";
  } else if (!IsVisibleChar(c)) {
    std::cout << "Non displayable\n";
  } else {
    std::cout << '\'' << c << "\'\n";
  }
}

void ScalarConverter::DisplayDoubleToInt(double d) {
  int i = static_cast<int>(d);

  std::cout << "int: ";
  if ((d > INT_MAX || d < INT_MIN) || !IsNormalDouble(d)) {
    std::cout << "Impossible\n";
  } else {
    std::cout << i << '\n';
  }
}

void ScalarConverter::DisplayDoubleToFloat(double d, long long int b) {
  const std::string imposible = "Impossible";
  const double kEpsilon = 9e-6;
  double d2 = static_cast<double>(static_cast<float>(d));

  std::cout << "float: ";
  if ((IsNormalDouble(d) && (d > FLT_MAX || d < -FLT_MAX)) || std::fabs(d - d2) >= kEpsilon) {
    std::cout << imposible << std::endl;
  } else if (static_cast<double>(b) != d) {
    std::cout << imposible << std::endl;
  } else {
    std::cout << std::fixed << static_cast<float>(d) << "f\n";
  }
}

void ScalarConverter::DisplayDouble(double d, long long int b) {
  std::cout << "double: ";
  if (static_cast<double>(b) != d) {
    std::cout << "Impossible\n";
  } else {
    std::cout << std::fixed << d << "\n";
  }
}

void ScalarConverter::Convert(const std::string &literal) {
  long long int b = atoll(literal.c_str());
  double d = atof(literal.c_str());
  if (IsNormalDouble(d) && !IsInputValid(literal)) {
    std::cout << "Invalid input\n";
    return;
  }

  std::cout.precision(2);
  if (d - static_cast<long long int>(d) == 0) {
    std::cout.precision(1);
  }
  DisplayDoubleToChar(d);
  DisplayDoubleToInt(d);
  DisplayDoubleToFloat(d, b);
  DisplayDouble(d, b);
}
