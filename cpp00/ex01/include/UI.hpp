#ifndef UTILS_H
#define UTILS_H

#include "Validator.hpp"
#include <string>

typedef bool (*fValidator)(const std::string&);

class UI {
public:
  static void clearStream();
  static bool eof();
  static std::string askStringInput(const std::string& to_ask);
  static std::string askStringInput(const std::string& to_ask, fValidator validator);
private:
  static bool eof_;
};

#endif  // UTILS_H