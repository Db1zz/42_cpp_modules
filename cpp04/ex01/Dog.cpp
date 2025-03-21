#include "Dog.hpp"
#include <iostream>

Dog::Dog()
  : _brain(new Brain())
{
  std::cout << "Dog's Default Constructor was called\n";
  _type = "Dog";
}

Dog::Dog(const Dog& to_copy)
  : Animal(to_copy), _brain(NULL)
{
  std::cout << "Dog's Copy Constructor was called\n";
  *this = to_copy;
}

Dog::~Dog() {
  std::cout << "Dog's Default Destructor was called\n";
  if (_brain) {
    delete _brain;
  }
}

Dog& Dog::operator=(const Dog& to_copy) {
  if (this == &to_copy) {
    return *this;
  }
  _type = to_copy._type;
  if (_brain) {
    delete _brain;
  }
  _brain = new Brain(*to_copy._brain);
  return *this;
}

void Dog::makeSound() const {
  std::cout << "Barking\n";
}