#include "Bureaucrat.h"
#include <iostream>

int main() {
  Bureaucrat bur("Aboba", 1);
  bur << std::cout << "WAS?\n";
	return 0;
}