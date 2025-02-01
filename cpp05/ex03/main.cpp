#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
  Intern intern;
  try {
    AForm *form = intern.MakeForm("shrubbery creation", "Aboba)");
    Bureaucrat bur("Fiend", 1);
    bur.SignForm(*form);
    bur.ExecuteForm(*form);
    std::cout << *form << std::endl;
    delete form;
  } catch (const std::exception &error) {
    std::cout << "Error! " << error.what() << std::endl;
  }
  return 0;
}