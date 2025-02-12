#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

#define CAST_MSG(type_str) std::string("Successfully casted Base* -> " + type_str)

Base *generate() {
  static int seed = 0;

  std::srand(std::time(NULL) + seed++);

  int random_value = std::rand();
  if (random_value % 3 == 0) {
    return new A;
  } else if (random_value % 2 == 0) {
    return new B;
  } else {
    return new C;
  }
}

void identify(Base* p) {
  std::string type = "";

  if (dynamic_cast<A*>(p) != NULL) {
    type = "A*";
  } else if (dynamic_cast<B*>(p) != NULL) {
    type = "B*";
  } else if (dynamic_cast<C*>(p) != NULL) {
    type = "C*";
  } else {
    std::cout << "Failed to cast Base* to: [A,B,C]\n";
    return;
  }
  std::cout << CAST_MSG(type) << std::endl;
}

void identify(Base& r) {
  std::string type = "";
  bool is_failed = false;

  try {
    A a = dynamic_cast<A&>(r);
    type = "A&";
  } catch (std::bad_cast) {
    is_failed = true;
  }
  try {
    B b = dynamic_cast<B&>(r);
    type = "B&";
  } catch (std::bad_cast) {
    is_failed = true;
  }
  try {
    C c = dynamic_cast<C&>(r);
    type = "C&";
  } catch (std::bad_cast) {
    is_failed = true;
  }
  if (is_failed) {
    std::cout << "Failed to cast Base& to " << type << std::endl;
  } else {
    std::cout << "Successfully casted Base& -> " << type << std::endl;
  }
}
