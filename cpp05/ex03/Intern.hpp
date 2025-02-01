#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"
#include <string>
#include <exception>

#define ALLOCATORS_DATA_SIZE 3

class Intern {
public:
  Intern();
  ~Intern();

  static AForm *MakeForm(
    const std::string &form_name,
    const std::string &target_name);

  class UnknownFormException : public std::exception {
  public:
    const char *what() const throw();
  };

  class MallocFailedException : public std::exception {
  public:
    const char *what() const throw();
  };

private:
  Intern &operator=(const Intern &copy);
  Intern(const Intern &copy);

  typedef AForm *(*FormAllocatorPtr)(const std::string &target);
  struct FormAllocatorData {
    std::string name;
    FormAllocatorPtr f;
  };

  static std::string StringToLower(const std::string &str);
  static AForm *ShrubberyCreationAllocator(const std::string &target);
  static AForm *RobotomyRequestAllocator(const std::string &target);
  static AForm *PresidentialPardonAllocator(const std::string &target);
};

#endif  // INTERN_H