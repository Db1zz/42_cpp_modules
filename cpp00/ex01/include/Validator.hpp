#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>

class Validator {
public:
  virtual bool validate(const std::string& str) = 0;
};

class PhoneNumberValidator : public Validator {
public:
  bool validate(const std::string& str);
private:
  int validate_country_code(const std::string& str);
  int validate_number(const std::string &str, int start);
};

#endif  // VALIDATOR_H
