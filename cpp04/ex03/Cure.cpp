#include "Cure.hpp"
#include <iostream>

Cure::Cure()
  : AMateria("cure")
{
  std::cout << "Cure Constructor was called\n";
}

Cure::Cure(const Cure& to_copy)
  : AMateria(to_copy._type)
{
  std::cout << "Cure's Copy Constructor was called\n";
}

Cure::~Cure() {
  std::cout << "Cure Destructor was called\n";
}

Cure& Cure::operator=(const Cure& to_copy) {
  if (this == &to_copy) {
    return *this;
  }
  _type = to_copy._type;
  return *this;
}

Cure* Cure::clone() const {
  return (new Cure());
}

void Cure::use(ICharacter& target) {
  std::cout << "Cure: * heals " << target.getName()<< "'s wounds *\n";
}
