#include "AForm.hpp"
#include <iostream>

AForm::AForm(
  const std::string &name,
  int req_grade_to_sign,
  int req_grade_to_execute)
	: name_(name),
    req_grade_to_execute_(req_grade_to_execute),
    req_grade_to_sign_(req_grade_to_sign),
    is_signed_(false)
{
  ValidateRequiredGrades();
}

AForm::AForm(const AForm &form)
	: name_(form.name_), 
    req_grade_to_execute_(form.req_grade_to_execute_),
    req_grade_to_sign_(form.req_grade_to_sign_),
    is_signed_(form.is_signed_) {}

AForm::~AForm() {}

const std::string &AForm::GetName() const {
  return name_;
}

int AForm::GetReqGradeToSign() const {
  return req_grade_to_sign_;
}

int AForm::GetReqGradeToExecute() const {
  return req_grade_to_execute_;
}

bool AForm::IsSigned() const {
  return is_signed_;
}

void AForm::BeSigned(const Bureaucrat &bur) {
  if (is_signed_) {
    throw SignSignedAFormException();
  }
  if (!IsBureaucratValid(bur.GetGrade())) {
    throw GradeTooLowException();
  }
  is_signed_ = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

const char *AForm::SignSignedAFormException::what() const throw() {
  return "Attempted to sign an already signed form";
}

void AForm::ValidateRequiredGrades() const {
  if (req_grade_to_execute_ > kGradeMin || req_grade_to_sign_ > kGradeMin) {
    throw GradeTooLowException();
  }
  if (req_grade_to_execute_ < kGradeMax || req_grade_to_sign_ < kGradeMax) {
    throw GradeTooHighException();
  }
}

bool AForm::IsBureaucratValid(int bureaucrat_grade) const {
  return bureaucrat_grade <= req_grade_to_sign_;
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
  return os << "============== Form Data ==============\n"
            << "Name: " << form.GetName() << '\n'
            << "Is signed: " << form.IsSigned() << '\n'
            << "Req. grade to execute: " << form.GetReqGradeToExecute() << '\n'
            << "Req. grade to sign: " << form.GetReqGradeToSign() << std::endl;
}
