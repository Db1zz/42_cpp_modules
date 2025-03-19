#include "Timer.hpp"
#include <sys/time.h>
#include <ctime>

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
  gettimeofday(&start_time_, NULL);
}

void Timer::stop() {
  gettimeofday(&end_time_, NULL);
}

time_t Timer::getMinutes() const {
  return (((getTimeInMilliseconds(end_time_) - getTimeInMilliseconds(start_time_)) / 1000 / 1000) / 60) % 60;
}

time_t Timer::getSeconds() const {
  return ((getTimeInMilliseconds(end_time_) - getTimeInMilliseconds(start_time_)) / 1000 / 1000) % 60;
}

time_t Timer::getMiliseconds() const {
  return (((getTimeInMilliseconds(end_time_) - getTimeInMilliseconds(start_time_)) / 1000) % 1000);
}

time_t Timer::getMicroseconds() const {
  return ((getTimeInMilliseconds(end_time_) - getTimeInMilliseconds(start_time_)) % 1000);
}

time_t Timer::getTimeInMilliseconds(const struct timeval &time) const {
  return (time.tv_sec * 1000 * 1000 + time.tv_usec);
}
