#include "ParserError.hpp"
#include "colors.hpp"

#include <sstream>
#include <iomanip>
#include <string>
#include <iostream>
#include <cstring>

ParserError::ParserError(const std::string &message, const char **input, int input_size, int position)
  : std::runtime_error(message), input_(input), input_size_(input_size), position_(position) {}

const char **ParserError::getInput() const {
  return input_;
}

int ParserError::getInputSize() const {
  return input_size_;
}

int ParserError::getPosition() const {
  return position_;
}

void ParserError::displayError() const {
  const int preview_size = 4;

  std::stringstream oss;
  int start_index = std::max(0, position_ - (preview_size - 1));
  int end_index = std::min(input_size_, start_index + preview_size);
  int error_highlight_pos = 0;

  oss << "[";

  if (position_ >= preview_size) {
    oss << input_[0] << ",";
    if (start_index > 0) {
      oss << "...,";
    }
  }

  for (int i = start_index; i < end_index; ++i) {
    if (i == position_) {
      error_highlight_pos = oss.tellp();
      oss << RED500 << input_[i] << RESET << ",";
      break;
    }
    oss << input_[i] << ",";
  }

  if (position_ != input_size_ - 1) {
    if ((input_size_ - 1) > preview_size && (input_size_ - 1 - end_index) > 0) {
      oss << "...,";
    }
    oss << input_[input_size_ - 1];
  } else {
    oss.seekp(-1, oss.cur);
  }

  oss << "]\n";
    std::cerr << oss.str();
    std::cerr << std::setfill(' ') << std::setw(error_highlight_pos) << ""
              << RED500 << std::setfill('^') << std::setw(strlen(input_[position_])) << ""
              << RESET << " " << what() << std::endl;
}