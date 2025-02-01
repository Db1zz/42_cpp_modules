#include "RobotomyRequestForm.hpp"
#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <time.h>

const std::string RobotomyRequestForm::kFormName = "RobotomyRequestForm";

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
  : AForm(target, kFormName, kSignGrade, kExecGrade) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
  : AForm(copy.target_, kFormName, kSignGrade, kExecGrade) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::Enforcement() const {
  for (int i = 0; i < 3; i++) {
    std::cout << "Makes some drilling noises\n";
    sleep(1);
  }
  std::srand(std::time(NULL));
  bool is_robotomized = std::rand() % 2 == 0;
  if (is_robotomized) {
    std::cout << "RobotomyRequestForm: " << target_
              << " has been robotomized successfully" << std::endl;
  } else {
    std::cout << "RobotomyRequestForm: " << "robotomy of the "
              << target_ << " has been failed" << std::endl;
  }
}
