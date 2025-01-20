#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "Character.hpp"
#include <string>

class AMateria {
public:
  AMateria(const std::string& type);
  AMateria(const AMateria& to_copy);
  virtual ~AMateria();
  AMateria& operator=(const AMateria& to_copy);

  virtual AMateria* clone() const = 0;

  virtual void use(ICharacter& target);
  const std::string& getType() const;

protected:
  std::string _type;
};

#endif  // AMATERIA_HPP