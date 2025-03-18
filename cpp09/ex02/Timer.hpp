#ifndef TIMER_HPP
# define TIMER_HPP

#include <ctime>

class Timer {
public:
  Timer();
  Timer(const Timer &to_copy);
  ~Timer();
  Timer &operator=(const Timer &to_copy);

  void start();
  std::time_t duration();

private:  
  std::time_t start_time_;
};

#endif  // TIMER_HPP