#ifndef FORM_H
# define FORM_H

# include <string>
# include <exception>

class Bureaucrat;

class Form {
public:
  Form(const Form &form);
  Form(
    const std::string &name = "Default",
    int req_grade_to_sign = kGradeMax,
    int req_grade_to_execute = kGradeMax);
  ~Form();

  const std::string &GetName() const;
  int GetReqGradeToSign() const;
  int GetReqGradeToExecute() const;
  bool IsSigned() const;

  void BeSigned(const Bureaucrat &bur);

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
  void ValidateRequiredGrades() const;
  bool IsBureaucratValid(int bureaucrat_grade) const;

  const std::string name_;
  const int req_grade_to_execute_;
  const int req_grade_to_sign_;
  bool is_signed_;

  static const int kGradeMin = 150;
  static const int kGradeMax = 1;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif  // FORM_H