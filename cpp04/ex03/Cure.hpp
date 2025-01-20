#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "Character.hpp"

class Cure : public AMateria {
public:
  Cure();
  Cure(const Cure& to_copy);
  ~Cure();
  Cure& operator=(const Cure& to_copy);

  Cure* clone() const;
  void use(ICharacter& target);
};

#endif  // CURE_HPP