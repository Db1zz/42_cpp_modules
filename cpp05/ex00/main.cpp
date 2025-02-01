#include "Bureaucrat.hpp"
#include <iostream>

int main() {
  try {
    Bureaucrat bur("SuperAboba", 0);
  } catch (const std::exception &error) {
    std::cout << "Failed to initialize Bureaucrat: " << error.what() << std::endl;
  }
  try {
    Bureaucrat bur("SuperAboba", 151);
  } catch (const std::exception &error) {
    std::cout << "Failed to initialize Bureaucrat: " << error.what() << std::endl;
  }
  try {
    Bureaucrat bur("SuperAboba", 1);
    std::cout << bur << '\n';
    bur.IncrementGrade();
  } catch (const std::exception &error) {
    std::cout << "Failed to increment grade: " << error.what() << std::endl;
  }
  try {
    Bureaucrat bur("SuperAboba", 150);
    std::cout << bur << '\n';
    bur.DecrementGrade();
  } catch (const std::exception &error) {
    std::cout << "Failed to decrement grade: " << error.what() << std::endl;
  }
	return 0;
}
