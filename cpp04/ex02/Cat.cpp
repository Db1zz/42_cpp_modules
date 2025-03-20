#include "Cat.hpp"
#include <iostream>

Cat::Cat()
  : _brain(new Brain())
{
  std::cout << "Cat's Default Constructor was called\n";
  _type = "Cat";
}

Cat::Cat(const Cat& to_copy)
  : Animal(to_copy), _brain(NULL)
{
  std::cout << "Cat's Copy Constructor was called\n";
  *this = to_copy;
}

Cat::~Cat() {
  std::cout << "Cat's Default Destructor was called\n";
  if (_brain) {
    delete _brain;
  }
}

Cat& Cat::operator=(const Cat& to_copy) {
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

void Cat::makeSound() const {
  std::cout << "Meowwwwwwww\n";
}