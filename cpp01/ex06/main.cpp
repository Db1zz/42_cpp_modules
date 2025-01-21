#include "Harl.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>

int main(int ac, char** av) {
  if (ac != 2) {
    std::cout << "Harl thinks that there's given too many arguments\n";
    return EXIT_FAILURE;
  }
  Harl harl;
  harl.complain(std::string(av[1]));
  return EXIT_SUCCESS;
}
