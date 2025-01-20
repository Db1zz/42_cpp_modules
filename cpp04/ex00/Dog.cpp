#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
  std::cout << "Dog's Default Constructor was called\n";
  _type = "Dog";
}

Dog::Dog(const Dog& to_copy) {
  std::cout << "Dog's Copy Constructor was called\n";
  _type = to_copy._type;
}

Dog::~Dog() {
  std::cout << "Dog's Default Destructor was called\n";
}

Dog& Dog::operator=(const Dog& to_copy) {
  if (this == &to_copy) {
    return *this;
  }
  _type = to_copy._type;
  return *this;
}

void Dog::makeSound() const {
  std::cout << "Barking\n";
}