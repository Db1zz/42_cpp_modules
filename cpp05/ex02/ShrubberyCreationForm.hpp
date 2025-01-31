#ifndef SHRUBBERY_CREATION_FORM_H
#define SHRUBBERY_CREATION_FORM_HH

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
  ShrubberyCreationForm();
  ~ShrubberyCreationForm();

  void ExecuteForm() const;

private:
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &form);

  static const int kSignGrade = 145;
  static const int kExecGrade = 137;
};

#endif  // SHRUBBERY_CREATION_FORM_HH