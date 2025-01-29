#include "Bureaucrat.h"
#include <iostream>

int main() {
  Bureaucrat bur("Aboba", 1);
  std::cout << bur << '\n';
  bur.decrement();
  std::cout << bur << '\n';
	return 0;
}