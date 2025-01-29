#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>

# define _GRADE_MAX 1
# define _GRADE_MIN 150 

class Bureaucrat {
public:
  Bureaucrat(const std::string &name, int grade);
  ~Bureaucrat();

  const std::string& getName() const;
  int getGrade() const;

  void increment();
  void decrement();

private:
  void _validate_grade();

  int _grade;
  const std::string _name;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bur);

#endif  // BUREAUCRAT_H