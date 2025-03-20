#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
  WrongCat();
  WrongCat(const WrongCat &to_copy);
  ~WrongCat();
  WrongCat &operator=(const WrongCat &to_copy);

  void makeSound() const;
};

#endif  // WRONG_CAT_HPP