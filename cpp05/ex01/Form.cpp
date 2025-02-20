#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form(
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

Form::Form(const Form &form)
	: name_(form.name_), 
    req_grade_to_execute_(form.req_grade_to_execute_),
    req_grade_to_sign_(form.req_grade_to_sign_),
    is_signed_(form.is_signed_) {}

Form::~Form() {}

const std::string &Form::GetName() const {
  return name_;
}

int Form::GetReqGradeToSign() const {
  return req_grade_to_sign_;
}

int Form::GetReqGradeToExecute() const {
  return req_grade_to_execute_;
}

bool Form::IsSigned() const {
  return is_signed_;
}

void Form::BeSigned(const Bureaucrat &bur) {
  if (is_signed_) {
    throw SignSignedFormException();
  }
  if (!IsBureaucratValid(bur.GetGrade())) {
    throw GradeTooLowException();
  }
  is_signed_ = true;
}

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

const char *Form::SignSignedFormException::what() const throw() {
  return "Attempted to sign an already signed form";
}

void Form::ValidateRequiredGrades() const {
  if (req_grade_to_execute_ > kGradeMin || req_grade_to_sign_ > kGradeMin) {
    throw GradeTooLowException();
  }
  if (req_grade_to_execute_ < kGradeMax || req_grade_to_sign_ < kGradeMax) {
    throw GradeTooHighException();
  }
}

bool Form::IsBureaucratValid(int bureaucrat_grade) const {
  return bureaucrat_grade <= req_grade_to_sign_;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
  return os << "============== Form Data ==============\n"
            << "Name: " << form.GetName() << '\n'
            << "Is signed: " << form.IsSigned() << '\n'
            << "Req. grade to execute: " << form.GetReqGradeToExecute() << '\n'
            << "Req. grade to sign: " << form.GetReqGradeToSign() << std::endl;
}
