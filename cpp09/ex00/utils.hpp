#ifndef UTILS_HPP
# define UTILS_HPP

#include <string>
#include <vector>

namespace utils {
  bool isFloat(const std::string &str);

  std::vector<std::string> split(
    const std::string &str, const std::string &delim);    
}

#endif  // UTILS_HPP