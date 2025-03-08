#ifndef ERROR_HPP
# define ERROR_HPP

#include <stdexcept>
#include <string>

class Error : public std::runtime_error {
public:
  Error(const std::string &message, const char **input, int input_size, int position);

  const char **getInput() const;
  int getInputSize() const;
  int getPosition() const;

private:
  const char **input_;
  int input_size_;
  int position_;
};

#endif  // ERROR_HPP