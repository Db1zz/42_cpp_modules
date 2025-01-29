#ifndef FORM_H
#define FORM_H

#include <string>

class Form {
public:
  Form(const Form& form);
  Form(int required_grade_to_sign=1, int required_grade_to_execute=1);
  ~Form();

private:
  const std::string _name;
  bool _is_signed;
  const int _required_grade_to_sign;
  const int _required_grade_to_execute;
};

#endif  // FORM_H