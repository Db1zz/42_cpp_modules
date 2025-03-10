#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <sstream>
#include <iostream>

Bureaucrat::Bureaucrat(const Bureaucrat& bur)
  : grade_(bur.grade_), name_(bur.name_) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
  : grade_(grade), name_(name)
{
  ValidateGrade(grade_);
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::GetName() const {
  return name_;
}

int Bureaucrat::GetGrade() const {
  return grade_;
}

void Bureaucrat::IncrementGrade() {
  ValidateGrade(grade_ - 1);
  grade_--;
}

void Bureaucrat::DecrementGrade() {
  ValidateGrade(grade_ + 1);
  grade_++;
}

void Bureaucrat::SignForm(AForm &form) {
  try {
    form.BeSigned(*this);
    std::cout << name_ << " signed " << form.GetName() << std::endl;
  } catch (const std::exception &error) {
    std::cout << name_ << " couldn't sign "
              << form.GetName() << " because: " << error.what() << "\n";
  }
}

void Bureaucrat::ExecuteForm(const AForm &form) const {
  try {
    form.Execute(*this);
    std::cout << name_ << " executed " << form.GetName() << std::endl;
  } catch (const std::exception &error) {
    std::cout << name_ << " couldn't execute "
              << form.GetName() << " because: " << error.what() << '\n';
  }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Bureaucrat: Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Bureaucrat: Grade is too low";
}

void Bureaucrat::ValidateGrade(int grade) const {
  if (grade < kGradeMax) {
    throw GradeTooHighException();
  }
  if (grade > kGradeMin) {
    throw GradeTooLowException();
  }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bur) {
  return os << bur.GetName() << ", bureaucrat grade: " << bur.GetGrade();
}