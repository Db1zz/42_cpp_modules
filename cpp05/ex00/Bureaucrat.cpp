#include "Bureaucrat.h"
#include <exception>
#include <sstream>
#include <iostream>

Bureaucrat::Bureaucrat(const Bureaucrat& bur)
  : _grade(bur._grade), _name(bur._name) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
  : _grade(grade), _name(name)
{
  _validate_grade();
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
  return _name;
}

int Bureaucrat::getGrade() const {
  return _grade;
}

void Bureaucrat::increment() {
  _grade--;
  _validate_grade();
}

void Bureaucrat::decrement() {
  _grade++;
  _validate_grade();
}

void Bureaucrat::_validate_grade() 
{
  try {
    if (_grade < _GRADE_MAX)
      throw std::runtime_error(std::string("Bureaucrat::GradeTooHighException"));
    else if (_grade > _GRADE_MIN) {
      throw std::runtime_error(std::string("Bureaucrat::GradeTooLowException"));
    }
  } catch (std::exception &exception) {
      std::cout << exception.what() << std::endl;
  }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bur) {
  return os << bur.getName() << ", bureaucrat grade: " << bur.getGrade();
}