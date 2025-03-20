#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
  std::cout << "WrongCat's Default Constructor was called\n";
  _type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& to_copy)
  : WrongAnimal(to_copy)
{  
  std::cout << "WrongCat's Copy Constructor was called\n";
  *this = to_copy;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat's Default Destructor was called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& to_copy) {
  if (this == &to_copy) {
    return *this;
  }
  _type = to_copy._type;
  return *this;
}

void WrongCat::makeSound() const {
  std::cout << "Meowwwwwwww\n";
}