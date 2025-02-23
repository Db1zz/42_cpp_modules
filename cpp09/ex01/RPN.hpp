#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <exception>

class RPN {
public:
  static int Solve(const std::string &expression);

private:
  RPN();
  typedef std::string::const_iterator StrCIt;

  class InvalidInputException : public std::exception {
  public:
    const char *what() const throw();
  };

  static bool IsOperator(char c);
  static char GetToken(StrCIt &it);
  static int PerformOperation(int left, int right, char op);
};

#endif // RPN_HPP