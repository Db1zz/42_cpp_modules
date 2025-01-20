#ifndef HARL_H
#define HARL_H

#include <string>

class Harl {
public:
  bool complain(const std::string& level);

private:
#define MAX_SIZE 4
  typedef void (Harl::*_func_p)();
  typedef struct {
    _func_p _func;
    std::string _name;
  } _FunctionData;

  void debug();
  void info();
  void warning();
  void error();
};

#endif  // HARL_H
