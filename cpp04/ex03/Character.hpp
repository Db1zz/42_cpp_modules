#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#define CHAR_INVENTORY_SIZE 4
#define UNEQUIPPED_MAX_SIZE 1024

class AMateria;

class ICharacter {
public:
  virtual ~ICharacter() {}
  virtual const std::string& getName() const = 0;
  virtual void equip(AMateria* materia) = 0;
  virtual void unequip(int idx) = 0;
  virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter {
public:
  Character(const std::string& name);
  Character(const Character& character);
  ~Character();
  Character& operator=(const Character& character);

  const std::string& getName() const;
  void equip(AMateria* materia);
  void unequip(int idx);
  void use(int idx, ICharacter& target);

private:
  void freeInventory();
  void copyInventory(const Character& character);
  void freeUnequippedMaterias();
  void copyUnequippedMaterias(const Character& character);
  void initCharacter();

  std::string _name;
  AMateria* _inventory[CHAR_INVENTORY_SIZE];
  int _invenotry_used;
  AMateria* _unequipped_materias[UNEQUIPPED_MAX_SIZE];
  int _uequipped_index;
};

#endif  // CHARACTER_HPP