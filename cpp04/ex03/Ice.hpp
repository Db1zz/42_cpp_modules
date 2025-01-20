#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "Character.hpp"

class Ice : public AMateria {
public:
  Ice();
  Ice(const Ice& to_copy);
  ~Ice();
  Ice& operator=(const Ice& to_copy);

  Ice* clone() const;
  void use(ICharacter& target);
};

#endif  // ICE_HPP