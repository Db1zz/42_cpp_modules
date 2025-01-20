#include "UI.hpp"
#include <iostream>

bool UI::eof_ = false;

void UI::clear_stream() {
  std::cin.clear();
  clearerr(stdin);
  eof_ = false;
}

bool UI::eof() {
  return eof_;
}

std::string UI::askStringInput(const std::string& to_ask) {
  std::string user_input;

  if (eof_ == true)
    return "";
  while (user_input.empty()) {
    std::cout << to_ask;
    std::getline(std::cin, user_input);
  }
  if (std::cin.eof()) {
    eof_ = true;
  }
  return user_input;
}

std::string UI::askStringInput(const std::string& to_ask, fValidator validator) {
  std::string user_input;

  while (true) {
    user_input = UI::askStringInput(to_ask);

    if (user_input.empty())
      return user_input;
    if (validator && !validator(user_input)) {
      user_input.clear();
      continue;
    }
    break;
  }
  return (user_input);
}
