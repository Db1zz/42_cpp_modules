#include "Error.hpp"

Error::Error(const std::string &message, const char **input, int input_size, int position)
  : std::runtime_error(message), input_(input), input_size_(input_size), position_(position) {}

const char **Error::getInput() const {
  return input_;
}

int Error::getInputSize() const {
  return input_size_;
}

int Error::getPosition() const {
  return position_;
}