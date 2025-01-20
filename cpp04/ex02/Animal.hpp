#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
public:
  Animal();
  Animal(const Animal& to_copy);
  virtual ~Animal();
  Animal& operator=(const Animal& to_copy);

  virtual void makeSound() const = 0;
  const std::string& getType() const;

protected:
  std::string _type;
};

#endif  // ANIMAL_HPP