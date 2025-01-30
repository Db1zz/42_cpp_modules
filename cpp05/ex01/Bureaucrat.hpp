#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <exception>

# define _GRADE_MAX 1
# define _GRADE_MIN 150 

class Bureaucrat {
public:
  Bureaucrat(const Bureaucrat& bur);
  Bureaucrat(const std::string &name="Aboba)", int grade=150);
  ~Bureaucrat();

  const std::string& getName() const;
  int getGrade() const;

  void increment();
  void decrement();

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };

  static bool validateGrade(int grade);

private:
  int _grade;
  const std::string _name;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bur);

#endif  // BUREAUCRAT_H