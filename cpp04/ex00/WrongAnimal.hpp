#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal {
public:
  WrongAnimal();
  WrongAnimal(const WrongAnimal& to_copy);
  ~WrongAnimal();
  WrongAnimal& operator=(const WrongAnimal& to_copy);

  void makeSound() const;
  const std::string& getType() const;

protected:
  std::string _type;
};

#endif  // WRONG_ANIMAL_HPP