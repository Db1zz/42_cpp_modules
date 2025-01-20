#include "Harl.hpp"
#include <iostream>
#include <string>

void Harl::debug() {
  std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::info() {
  std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning() {
  std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error() {
  std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

bool Harl::complain(const std::string& level) {
  static _FunctionData fncts[MAX_SIZE] = {
    {&Harl::debug, "DEBUG"},
    {&Harl::info, "INFO"},
    {&Harl::warning, "WARNING"},
    {&Harl::error, "ERROR"}
  };

  for (int i = 0; i < MAX_SIZE; i++) {
    if (fncts[i]._name == level) {
      for (int j = i; j < MAX_SIZE; j++) {
        std::cout << "[ " << fncts[j]._name << " ]\n";
        (this->*(fncts[j]._func))();
        std::cout << '\n';
      }
      return true;
    }
  }
  return false;
}
