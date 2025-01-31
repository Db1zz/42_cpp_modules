#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int main() {

  try {
    Bureaucrat bur("SuperAboba", 1);
    AForm form("Abobu's upgrade", 0, 151);
  }  catch (const std::exception &error) {
    std::cout << "Baka! This class cannot be initialized with this error: "
              << error.what() << "\nBOOM!" << std::endl;
  }
  {
    Bureaucrat bur("SuperAboba", 1);
    AForm form("Abobu's upgrade", 1, 1);
    std::cout << form << std::endl;
    bur.SignForm(form);
    bur.SignForm(form);
    std::cout << form << std::endl;
  }
	return 0;
}
