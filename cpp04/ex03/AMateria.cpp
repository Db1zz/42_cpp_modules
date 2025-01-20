#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(const std::string& type)
  : _type(type)
{
  std::cout << "AMateria Constructor was called\n";
}

AMateria::AMateria(const AMateria& to_copy)
  : _type(to_copy._type)
{
  std::cout << "AMateria's Copy Constructor was called\n";
}

AMateria::~AMateria() {
  std::cout << "AMateria Destructor was called\n";
}

AMateria& AMateria::operator=(const AMateria& to_copy) {
  if (this == &to_copy) {
    return *this;
  }
  _type = to_copy._type;
  return *this;
}

const std::string& AMateria::getType() const {
  return _type;
}

void AMateria::use(ICharacter &target) {
  std::cout << "Materia: * unknown materia used on " << target.getName() << " *\n";
}
