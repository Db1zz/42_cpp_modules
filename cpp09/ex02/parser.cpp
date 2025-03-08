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
    return 0;
  } else if (i <= 0) {
    error_message = "The number is less than or equal to zero";
    return 0;
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
    if (!number) {
      throw Error(error_message, num_str_array, size, i);
    }
    temp.push_back(number);
  }

  result = temp;
}

void display_error(const Error &e) {
  const char **input = e.getInput();
  const int input_size = e.getInputSize();
  const int preview_size = 5;

  std::stringstream oss;
  int start_index = std::max(0, e.getPosition() - (preview_size - 1));
  int end_index = std::min(input_size, start_index + preview_size);
  int error_highlight_pos = 0;

  oss << "[";

  if (e.getPosition() >= preview_size) {
    oss << input[0] << ",";
    if (start_index > 0) {
      oss << "...,";
    }
  }

  for (int i = start_index; i < end_index; ++i) {
    if (i == e.getPosition()) {
      error_highlight_pos = oss.tellp();
      oss << RED500 << input[i] << RESET << ",";
      break;
    }
    oss << input[i] << ",";
  }

  if (e.getPosition() != input_size - 1) {
    if ((input_size - 1) > preview_size && (input_size - 1 - end_index) > 0) {
      oss << "...,";
    }
    oss << input[input_size - 1];
  } else {
    oss.seekp(-1, oss.cur);
  }

  oss << "]\n";
    std::cerr << oss.str();
    std::cerr << std::setfill(' ') << std::setw(error_highlight_pos) << ""
              << RED500 << std::setfill('^') << std::setw(strlen(input[e.getPosition()])) << ""
              << RESET << " " << e.what() << std::endl;
}