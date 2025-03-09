#include "parser.hpp"
#include "colors.hpp"
#include <sstream>
#include <iomanip>
#include <string>
#include <iostream>

int validate_positive_integer(const char *s, std::string &error_message) {
  std::string str(s);
  std::istringstream iss(str);
  int i;

  if (!(iss >> std::noskipws >> i && iss.eof())) {
    error_message = "The number contains non-numeric characters";
    return -1;
  } else if (i < 0) {
    error_message = "The number is less than or equal to zero";
    return -1;
  }
  return i;
}

void parse_input(const char **num_str_array, int size, std::vector<int> &result)
{
  if (size == 0) {
    throw std::runtime_error("Invalid amount of arguments");
  }

  std::string error_message;
  std::vector<int> temp;
  temp.reserve(size);

  for (int i = 0; i < size; ++i) {
    int number = validate_positive_integer(num_str_array[i], error_message);
    if (number < 0) {
      throw ParserError(error_message, num_str_array, size, i);
    }
    temp.push_back(number);
  }

  result = temp;
}
