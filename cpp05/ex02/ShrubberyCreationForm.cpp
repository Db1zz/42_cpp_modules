#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
  : AForm("ShrubberyCreationForm", kSignGrade, kExecGrade) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::Execute(const Bureaucrat &bureaucrat) const {
  std::ofstream outfile();
}