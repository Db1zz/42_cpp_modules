#ifndef HARL_H
#define HARL_H

#include <string>

class Harl {
public:
  void complain(const std::string& level);

private:
  enum _state{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    TOTAL
  };

  _state levelToState(const std::string& level);

  void debug();
  void info();
  void warning();
  void error();
  void unknown();
};

#endif  // HARL_H
