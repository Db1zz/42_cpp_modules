#include "Harl.hpp"
#include <iostream>
#include <string>

void Harl::debug() {
  std::cout << "[ DEBUG ]\n"
            << "I love having extra bacon for my "
               "7XL-double-cheese-triple-pickle-specialketchup burger. I "
               "really do!\n\n";
}

void Harl::info() {
  std::cout << "[ INFO ]\n"
            << "I cannot believe adding extra bacon costs more money. You "
               "didn’t put enough bacon in my burger! If you did, I wouldn’t "
               "be asking for more!\n\n";
}

void Harl::warning() {
  std::cout << "[ WARNING ]\n"
            << "I think I deserve to have some extra bacon for free. I’ve been "
               "coming for years whereas you started working here since last "
               "month.\n\n";
}

void Harl::error() {
  std::cout << "[ ERROR ]\n"
            << "This is unacceptable! I want to speak to the manager now.\n\n";
}

void Harl::unknown() {
  std::cout << "[ Probably complaining about insignificant problems ]\n";
}

Harl::_state Harl::levelToState(const std::string &level) {
  const static _StateData data[] = {
      {DEBUG, "DEBUG"}, {INFO, "INFO"}, {WARNING, "WARNING"}, {ERROR, "ERROR"}};
  for (int i = 0; i < static_cast<int>(TOTAL); i++) {
    if (level == data[i].name) {
      return data[i].state;
    }
  }
  return TOTAL;
}

void Harl::complain(const std::string &level) {
  _state state = levelToState(level);

  switch (state) {
  case DEBUG:
    debug();
  case INFO:
    info();
  case WARNING:
    warning();
  case ERROR:
    error();
    break;
  default:
    unknown();
  }
}
