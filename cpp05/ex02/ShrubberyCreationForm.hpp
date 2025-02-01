#ifndef SHRUBBERY_CREATION_FORM_H
#define SHRUBBERY_CREATION_FORM_H

#include "AForm.hpp"
#include <string>
#include <exception>

class ShrubberyCreationForm : public AForm {
public:
  ShrubberyCreationForm(const std::string &target="Home");
  ShrubberyCreationForm(const ShrubberyCreationForm &form);
  ~ShrubberyCreationForm();

  const std::string &GetTarget() const;

  void Execute(const Bureaucrat &bureaucrat) const;

  class OpenFileException : public std::exception {
  public:
    const char *what() const throw();
  };

private:
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &form);
  void CheckTargetName() const;
  const std::string target_;

  static const int kSignGrade = 145;
  static const int kExecGrade = 137;
  static const std::string kFormName;
};

#endif  // SHRUBBERY_CREATION_FORM_H  