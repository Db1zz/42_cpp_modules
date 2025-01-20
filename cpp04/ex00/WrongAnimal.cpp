#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
  : _type("WrongAnimal")
{
  std::cout << "WrongAnimal's Default Constructor was called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& to_copy)
  : _type(to_copy._type)
{
  std::cout << "WrongAnimal's Copy Constructor was called\n";
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal's Default Destructor was called\n"; 
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& to_copy) {
  if (this == &to_copy) {
    return *this;
  }
  _type = to_copy._type;  
  return *this;
}

void WrongAnimal::makeSound() const {
  std::cout << "Animal sound\n";
}

const std::string& WrongAnimal::getType() const {
  return _type;
}