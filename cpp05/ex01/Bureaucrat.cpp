#include "Bureaucrat.hpp"
#include <sstream>
#include <iostream>

bool Bureaucrat::validateGrade(int grade) {
  if (grade < _GRADE_MAX) {
    throw GradeTooHighException();
  }
  else if (grade > _GRADE_MIN) {
    throw GradeTooLowException();
  } else {
    return true;
  }
  return false;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bur)
  : _grade(bur._grade), _name(bur._name) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
  : _grade(grade), _name(name)
{
  if (!validateGrade(_grade)) {
    std::cout << "Error: Attempted to initialize class with invalid grade! "
              << "Default grade " << _GRADE_MIN << " will be assigned." << std::endl;
    _grade = _GRADE_MIN;
  }
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
  return _name;
}

int Bureaucrat::getGrade() const {
  return _grade;
}

void Bureaucrat::increment() {
  if (validateGrade(_grade - 1)) {
    _grade--;
  }
}

void Bureaucrat::decrement() {
  if (validateGrade(_grade + 1)) {
    _grade++;
  }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Exception throwed: Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Exception throwed: Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bur) {
  return os << bur.getName() << ", bureaucrat grade: " << bur.getGrade();
}