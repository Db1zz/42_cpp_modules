#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av) {
  if (ac != 2) {
    std::cerr << "Incorrect amount of arguments are given: "
              << "Try: 1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /" << std::endl;
    return -1;
  }
  try {
    int result = RPN::Solve(std::string(av[1]));
    std::cout << "Expression result: " << result << std::endl;
  } catch (const std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  return 0;
}