#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <exception>

class AForm;

class Bureaucrat {
public:
  Bureaucrat(const Bureaucrat &bur);
  Bureaucrat(const std::string &name="Aboba)", int grade=150);
  ~Bureaucrat();

  const std::string &GetName() const;
  int GetGrade() const;

  void IncrementGrade();
  void DecrementGrade();

  void SignForm(AForm &form);

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };

private:
  void ValidateGrade(int grade) const;
  Bureaucrat &operator=(Bureaucrat &bureaucrat);

  int grade_;
  const std::string name_;

  static const int kGradeMin = 150;
  static const int kGradeMax = 1;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bur);

#endif  // BUREAUCRAT_H