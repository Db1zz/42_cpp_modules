#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

AForm *Intern::MakeForm(
  const std::string &form_name,
  const std::string &target_name)
{
  static const FormAllocatorData allocators_data[ALLOCATORS_DATA_SIZE] = {
    {"shrubbery creation", ShrubberyCreationAllocator},
    {"presidential pardon", PresidentialPardonAllocator},
    {"robotomy request", RobotomyRequestAllocator}
  };

  for (int i = 0; i < ALLOCATORS_DATA_SIZE; i++) {
    if (allocators_data[i].name == StringToLower(form_name)) {
      AForm *form = allocators_data[i].f(target_name);
      if (!form) {
        throw MallocFailedException();
      }
      return form;
    }
  }
  throw UnknownFormException();
}

const char *Intern::UnknownFormException::what() const throw() {
  return "Intern: Cannot find a form with the given name";
}

const char *Intern::MallocFailedException::what() const throw() {
  return "Intern: Malloc failed to allocate memory";
}

std::string Intern::StringToLower(const std::string &str) {
  std::string upper_case_string(str.length(), '\0');

  for (int i = 0; str[i]; i++) {
    upper_case_string[i] = std::tolower(str[i]);
  }
  return upper_case_string;
}

AForm *Intern::ShrubberyCreationAllocator(const std::string &target) {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::RobotomyRequestAllocator(const std::string &target) {
  return new RobotomyRequestForm(target);
}

AForm *Intern::PresidentialPardonAllocator(const std::string &target) {
  return new PresidentialPardonForm(target);
}