#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
  std::cout << "========= Normal Animals =========\n";
  const Animal* animal_base = new Animal();
  const Animal* sliced_dog = new Dog();
  const Animal* sliced_cat = new Cat();

  std::cout << sliced_dog->getType() << " " << std::endl;
  std::cout << sliced_cat->getType() << " " << std::endl;

  sliced_cat->makeSound(); // will output the cat sound!
  sliced_dog->makeSound();
  animal_base->makeSound();

  delete animal_base;
  delete sliced_dog;
  delete sliced_cat;

  std::cout << "\n========= Wrong Animals =========\n";
  const WrongAnimal* wrong_animal_base = new WrongAnimal();
  const WrongAnimal* sliced_wrong_cat = new WrongCat();

  std::cout << sliced_wrong_cat->getType() << " " << std::endl;

  sliced_wrong_cat->makeSound(); // will output the animal sound!
  wrong_animal_base->makeSound();
  
  delete wrong_animal_base;
  delete sliced_wrong_cat;

  return 0;
}