#include "Timer.hpp"

Timer::Timer() {
  start();
}

Timer::Timer(const Timer &to_copy) {
  *this = to_copy;
}

Timer::~Timer() {}

Timer &Timer::operator=(const Timer &to_copy) {
  if (this == &to_copy) {
    start_time_ = to_copy.start_time_;
  }
  return *this;
}

void Timer::start() {
  start_time_ = std::time(NULL);
}

std::time_t Timer::duration() {
  return std::time(NULL) - start_time_;
}
