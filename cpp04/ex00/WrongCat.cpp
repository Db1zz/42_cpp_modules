#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
  std::cout << "WrongCat's Default Constructor was called\n";
  _type = "WrongCat";
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat's Default Destructor was called\n";
}

void WrongCat::makeSound() const {
  std::cout << "Meowwwwwwww\n";
}