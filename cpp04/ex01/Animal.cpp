#include "Animal.hpp"
#include <iostream>

Animal::Animal()
  : _type("Animal")
{
  std::cout << "Animal's Default Constructor was called\n";
}

Animal::Animal(const Animal& to_copy)
  : _type(to_copy._type)
{
  std::cout << "Animal's Copy Constructor was called\n";
}

Animal::~Animal() {
  std::cout << "Animal's Default Destructor was called\n";
}

Animal& Animal::operator=(const Animal& to_copy) {
  if (this == &to_copy) {
    return *this;
  }
  _type = to_copy._type;  
  return *this;
}

void Animal::makeSound() const {
  std::cout << "Animal makes sound\n";
}

const std::string& Animal::getType() const {
  return _type;
}