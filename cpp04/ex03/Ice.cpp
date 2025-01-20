#include "Ice.hpp"
#include <iostream>

Ice::Ice()
  : AMateria("ice")
{
  std::cout << "Ice Constructor was called\n";
}

Ice::Ice(const Ice& to_copy)
  : AMateria(to_copy._type)
{
  std::cout << "Ice's Copy Constructor was called\n";
}

Ice::~Ice() {
  std::cout << "Ice Destructor was called\n";
}

Ice& Ice::operator=(const Ice& to_copy) {
  if (this == &to_copy) {
    return *this;
  }
  _type = to_copy._type;
  return *this;
}

Ice* Ice::clone() const {
  return (new Ice());
}

void Ice::use(ICharacter& target) {
  std::cout << "Ice: * shoots an ice bolt at " << target.getName() << " *\n";
}
