#include "Validator.hpp"
#include <cctype>
#include <iostream>

#define COUNTRY_CODE_MAX_LENGHT 4
#define NUMBER_MIN_LENGHT 3

int PhoneNumberValidator::validate_country_code(const std::string &str) {
  int code_lenght = 0;

  if (str[code_lenght] == '+') {
    code_lenght++;
  } else if (isdigit(str[code_lenght])) {
    return 0;
  } else {
    return -1;
  }

  while (isdigit(str[code_lenght]) && code_lenght < COUNTRY_CODE_MAX_LENGHT) {
    code_lenght++;
  };

  if (str[code_lenght] == ' ' && code_lenght > 1) {
    return code_lenght + 1;
  } else if (isdigit(str[code_lenght])) {
    return code_lenght;
  }
  return -1;
}

int PhoneNumberValidator::validate_number(const std::string &str, int start) {
  int num_index = start;
  int num_lenght = 0;

  while (isdigit(str[num_index])) {
    num_index++;
    num_lenght++;
  }
  if (str[num_index] != '\0' || num_lenght < NUMBER_MIN_LENGHT) {
    return -1;
  }
  return num_lenght;
}

bool PhoneNumberValidator::validate(const std::string &str) {
  int code_lenght = validate_country_code(str);

  if (code_lenght < 0) {
    std::cout << "Invalid country code!\n";
    return false;
  }
  int number_lenght = validate_number(str, code_lenght);
  if (number_lenght < 0) {
    std::cout << "Invalid number!\n";
    return false;
  }
  return true;
}
