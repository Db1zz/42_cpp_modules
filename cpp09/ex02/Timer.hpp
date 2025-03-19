#ifndef TIMER_HPP
# define TIMER_HPP

#include <sys/time.h>

class Timer {
public:
  Timer();
  Timer(const Timer &to_copy);
  ~Timer();
  Timer &operator=(const Timer &to_copy);

  void start();
  void stop();
  time_t getMinutes() const;
  time_t getSeconds() const;
  time_t getMiliseconds() const;
  time_t getMicroseconds() const;

private:  
  time_t getTimeInMilliseconds(const struct timeval &time) const;

  struct timeval start_time_;
  struct timeval end_time_;
};

#endif  // TIMER_HPP