#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
  std::cout << "Cat's Default Constructor was called\n";
  _type = "Cat";
}

Cat::Cat(const Cat& to_copy) {
  std::cout << "Cat's Copy Constructor was called\n";
  _type = to_copy._type;
}

Cat::~Cat() {
  std::cout << "Cat's Default Destructor was called\n";
}

Cat& Cat::operator=(const Cat& to_copy) {
  if (this == &to_copy) {
    return *this;
  }
  _type = to_copy._type;  
  return *this;
}

void Cat::makeSound() const {
  std::cout << "Meowwwwwwww\n";
}