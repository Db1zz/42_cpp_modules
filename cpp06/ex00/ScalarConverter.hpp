#ifndef SCALAR_CONVERTER_H
#define SCALAR_CONVERTER_H

#include <string>

class ScalarConverter {
public:
  static void Convert(const std::string &literal);

private:
  static void display_double(double d);
  static void display_double_to_float(double d);
  static void display_double_to_int(double d);
  static void display_double_to_char(double d);
  static bool is_visible_char(char c);
  static bool is_normal_double(double val);

  ScalarConverter &operator=(const ScalarConverter &copy);
  ScalarConverter();
  ~ScalarConverter();
};

#endif  // SCALAR_CONVERTER_H
