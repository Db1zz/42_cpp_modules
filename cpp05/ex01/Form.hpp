#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"
#include <string>
#include <exception>

class Form {
public:
  Form(const Form& form);
  Form(
    const std::string &name,
    int req_grade_to_sign,
    int req_grade_to_execute);
  ~Form();

  const std::string &getName() const;
  int getReqGradeToSign() const;
  int getReqGradeToExecute() const;
  bool isSigned() const;

  void beSigned(const Bureaucrat &bur);
  bool signForm(const Bureaucrat &bur);

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };

  class SignSignedFormException : public std::exception {
  public:
    const char *what() const throw();
  };

private:
  bool _validateRequiredGrades();
  bool _validateBurGrade(int bur_grade);

  const std::string _name;
  const int _req_grade_to_execute;
  const int _req_grade_to_sign;
  bool _is_signed;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif  // FORM_H