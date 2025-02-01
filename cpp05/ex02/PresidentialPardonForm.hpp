#ifndef PRESIDENTIAL_PARDON_FORM_H
#define PRESIDENTIAL_PARDON_FORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
  PresidentialPardonForm(const std::string &target = "Target");
  PresidentialPardonForm(const PresidentialPardonForm &copy);
  ~PresidentialPardonForm();

  void Enforcement() const;

private:
  PresidentialPardonForm &operator=(const PresidentialPardonForm &form);

  static const int kSignGrade = 25;
  static const int kExecGrade = 5;
  static const std::string kFormName;
};

#endif  // PRESIDENTIAL_PARDON_FORM_H