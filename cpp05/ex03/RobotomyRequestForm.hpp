#ifndef ROBOTOMY_REQUEST_FORM_H
#define ROBOTOMY_REQUEST_FORM_H

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
  RobotomyRequestForm(const std::string &target = "Target");
  RobotomyRequestForm(const RobotomyRequestForm &copy);
  ~RobotomyRequestForm();

  void Enforcement() const;

private:
  RobotomyRequestForm &operator=(const RobotomyRequestForm &form);

  static const int kSignGrade = 72;
  static const int kExecGrade = 45;
  static const std::string kFormName;
};

#endif  // ROBOTOMY_REQUEST_FORM_H§