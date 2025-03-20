#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>

Animal** create_animals(int size) {
  Animal** animals = new Animal*[size + 1];

  for (int i = 0; i < size; ++i) {
    if (i % 2 == 0) {
      animals[i] = new Dog();
    } else {
      animals[i] = new Cat();
    }
  }
  animals[size] = NULL;
  return animals;
}

void delete_animals(Animal** animals, int size) {
  for (int i = 0; i < size; ++i) {
    if (animals[i]) {
      delete animals[i];
    }
  }
  delete[] animals;
}

int main() {
  const int size = 2;

  std::cout << "=========== Creating Animals ===========\n";
  Animal** animals = create_animals(size);

  std::cout << "\n=========== Deleting Animals ===========\n";
  delete_animals(animals, size);

  Dog basic_dog;
  Cat basic_cat;
  {
    Dog tmp_dog = basic_dog;
    Cat tmp_cat = basic_cat;
  }
  basic_dog.makeSound();
  basic_cat.makeSound();
  return 0;
}