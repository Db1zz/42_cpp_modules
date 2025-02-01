#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"
#include <string>
#include <exception>

class AForm {
public:
  AForm(const AForm &form);
  AForm(const std::string &target = "Target",
        const std::string &name = "Name",
        int req_grade_to_sign = kGradeMin,
        int req_grade_to_execute = kGradeMin);
  ~AForm();

  const std::string &GetName() const;
  int GetReqGradeToSign() const;
  int GetReqGradeToExecute() const;
  bool IsSigned() const;

  void BeSigned(const Bureaucrat &bur);
  void Execute(const Bureaucrat &bureaucrat) const;
  virtual void Enforcement() const = 0;

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };

  class SignSignedAFormException : public std::exception {
  public:
    const char *what() const throw();
  };

  class UnsignedFormException : public std::exception {  public:
    const char *what() const throw();
  };

  class EmptyTargetNameException : public std::exception {
  public:
    const char *what() const throw();
  };

  const std::string &GetTarget() const;

  void ValidateName() const;

protected:
  bool CanSign(const Bureaucrat &bur) const;
  bool CanExecute(const Bureaucrat &bur) const;
  const std::string target_;

private:
  void ValidateRequiredGrades() const;
  AForm &operator=(const AForm &form);

  const std::string name_;
  const int req_grade_to_execute_;
  const int req_grade_to_sign_;
  bool is_signed_;

  static const int kGradeMin = 150;
  static const int kGradeMax = 1;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif  // FORM_H