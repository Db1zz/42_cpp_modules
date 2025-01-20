#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include <iostream>

int main() {
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter* me = new Character("me");
  AMateria* tmp;

  tmp = src->createMateria("ice");
  me->equip(tmp);

  tmp = src->createMateria("cure");
  me->equip(tmp);

  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  Character bob2("abobus");

  tmp = src->createMateria("cure");
  bob2.equip(tmp);

  {
    Character tmp = bob2;
    std::cout << tmp.getName() << "copy\n";
  }
  std::cout << "----\n";
  delete bob;
  delete me;
  delete src;

  return 0;
}
