#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character(const std::string& name)
  : _name(name), _invenotry_used(0), _uequipped_index(0)
{
  std::cout << "Character Constructor was called\n";
}

Character::Character(const Character& character)
{
  std::cout << "Character Copy Constructor was called\n";
  *this = character;
}

Character::~Character() {
  std::cout << "Character Destructor was called\n";
  freeInventory();
  freeUnequippedMaterias();
}

Character& Character::operator=(const Character& character) {
  if (this == &character) {
    return *this;
  }
  copyInventory(character);
  _name = character._name;
  return *this;
}

const std::string& Character::getName() const {
  return _name;
}

void Character::equip(AMateria* materia) {
  if (materia == NULL) {
    return;
  } else if (_invenotry_used == CHAR_INVENTORY_SIZE) {
    return;
  }
  for (int i = 0; i < CHAR_INVENTORY_SIZE; i++) {
    if (_inventory[i] == NULL) {
      _inventory[i] = materia;
      _invenotry_used++;
      return;
    }
  }
}

void Character::unequip(int idx) {
  if (idx >= CHAR_INVENTORY_SIZE || idx < 0) {
    return;
  } else if (!_inventory[idx]) {
    return;
  }
  _unequipped_materias[_uequipped_index++] = _inventory[idx];
  _inventory[idx] = NULL;
  _invenotry_used--;
}

void Character::use(int idx, ICharacter& target) {
  if (idx >= CHAR_INVENTORY_SIZE || idx < 0) {
    return;
  } else if (!_inventory[idx]) {
    return;
  }
  _inventory[idx]->use(target);
}

void Character::freeInventory() {
  for (int i = 0; i < CHAR_INVENTORY_SIZE; i++) {
    if (_inventory[i]) {
      delete _inventory[i];
      _inventory[i] = NULL;
    }
  }
}

void Character::freeUnequippedMaterias() {
  for (int i = 0; i < _uequipped_index; i++) {
    if (_unequipped_materias[i]) {
      delete _unequipped_materias[i];
      _unequipped_materias[i] = NULL;
    }
  }
}

void Character::copyInventory(const Character& character) {
  _invenotry_used = 0;
  for (int i = 0; i < CHAR_INVENTORY_SIZE; i++) {
    if (_inventory[i]) {
      delete _inventory[i];
      _inventory[i] = NULL;
    }
    if (character._inventory[i]) {
      _inventory[i] = character._inventory[i]->clone();
      _invenotry_used++;
    }
  }
}
