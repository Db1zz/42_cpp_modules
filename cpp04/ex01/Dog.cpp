#include "Dog.hpp"
#include <iostream>

Dog::Dog()
  : _brain(new Brain())
{
  std::cout << "Dog's Default Constructor was called\n";
  _type = "Dog";
}

Dog::Dog(const Dog& to_copy) {
  std::cout << "Dog's Copy Constructor was called\n";
  _type = to_copy._type;
  _brain = to_copy._brain;
}

Dog::~Dog() {
  std::cout << "Dog's Default Destructor was called\n";
  delete _brain;
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