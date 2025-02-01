#include "PresidentialPardonForm.hpp"
#include <iostream>

const std::string PresidentialPardonForm::kFormName = "PresidentialPardonForm";

PresidentialPardonForm:: PresidentialPardonForm(const std::string &target)
  : AForm(target, kFormName, kSignGrade, kExecGrade) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy.target_, kFormName, kSignGrade, kExecGrade) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::Enforcement() const {
  std::cout << target_ << " has been pardoned by "
            << "Zaphod Beeblebrox" << std::endl;
}
