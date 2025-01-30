#include "Form.hpp"
#include <iostream>

Form::Form(
  const std::string &name,
  int req_grade_to_sign,
  int req_grade_to_execute)
	: _name(name),
    _req_grade_to_execute(req_grade_to_execute),
    _req_grade_to_sign(req_grade_to_sign),
    _is_signed(false)
{
  try {
    _validateRequiredGrades();
  } catch (const char *error) {
    std::cout << "Baka! This class cannot be initialized with this error: "
              << error << "\nBOOM!" << std::endl;
    std::terminate();
  }
}

Form::Form(const Form& form)
	: _name(form._name), 
    _req_grade_to_execute(form._req_grade_to_execute),
    _req_grade_to_sign(form._req_grade_to_sign),
    _is_signed(form._is_signed) {}

Form::~Form() {}

const std::string &Form::getName() const {
  return _name;
}

int Form::getReqGradeToSign() const {
  return _req_grade_to_sign;
}

int Form::getReqGradeToExecute() const {
  return _req_grade_to_execute;
}

bool Form::isSigned() const {
  return _is_signed;
}

void Form::beSigned(const Bureaucrat &bur) {
  if (_is_signed) {
    throw SignSignedFormException();
  } 
  if (_validateBurGrade(bur.getGrade())) {
    _is_signed = true;
  }
}

bool Form::signForm(const Bureaucrat &bur) {
  try {
    beSigned(bur);
  } catch (const char *err) {
    std::cout << bur.getName() << " couldn't sign "
              << _name << " reason: " << err << "\n";
  }
  std::cout << bur.getName() << bur.getName() << " signed " << _name << std::endl;
  return true;
}

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

const char *Form::SignSignedFormException::what() const throw() {
  return "Attempted to sign signed form";
}

bool Form::_validateRequiredGrades() {
  if (_req_grade_to_execute > _GRADE_MIN || _req_grade_to_sign > _GRADE_MIN) {
      throw GradeTooLowException();
  } else if (_req_grade_to_execute < _GRADE_MAX || _req_grade_to_sign < _GRADE_MAX) {
      throw GradeTooHighException();
  } else {
    return true;
  }
  return false;
}

bool Form::_validateBurGrade(int bur_grade) {
  if (bur_grade > _req_grade_to_execute || bur_grade > _req_grade_to_sign) {
    throw GradeTooLowException();
  } else {
    return true;
  }
  return false;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
  return os << "============== Form Data ==============\n"
            << "Name: " << form.getName() << '\n'
            << "Is signed: " << form.isSigned() << '\n'
            << "Req. grade to execute: " << form.getReqGradeToExecute() << '\n'
            << "Req. grade to sign: " << form.getReqGradeToSign() << std::endl;
}
