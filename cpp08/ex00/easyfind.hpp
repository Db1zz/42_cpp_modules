#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iostream>

class ObjectNotFound : public std::exception {
public:
  const char *what() const throw() {
    return "std::find failed to find a value in the container";
  }
};

template <typename T>
void easyfind(const T &container, int value) {
  typename T::const_iterator it = std::find(container.begin(), container.end(), value);
  if (it == container.end())
    throw ObjectNotFound();
  std::cout << "easyfind() found this value: " << value << std::endl;
}

#endif // EASYFIND_HPP