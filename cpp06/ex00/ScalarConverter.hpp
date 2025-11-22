#ifndef SCALAR_CONVERTER_H
#define SCALAR_CONVERTER_H

#include <string>

class ScalarConverter {
public:
  static void Convert(const std::string &literal);

private:
  static bool IsInputValid(const std::string &input);
  static void DisplayDouble(double d);
  static void DisplayDoubleToFloat(double d);
  static void DisplayDoubleToInt(double d);
  static void DisplayDoubleToChar(double d);
  static bool IsVisibleChar(char c);
  static bool IsNormalDouble(double val);
  static bool DotChecker(int i, const std::string &input, bool dot_found, bool exp_found);
  static bool DecimalChecker(int i, const std::string &input, bool dot_found, bool exp_found);
  static bool ExponentChecker(int i, const std::string &input, bool dot_found, bool exp_found);

  ScalarConverter &operator=(const ScalarConverter &copy);
  ScalarConverter();
  ~ScalarConverter();
};

#endif  // SCALAR_CONVERTER_H
