#include "A.hpp"
#include "C.hpp"
#include "B.hpp"
#include "Base.hpp"

#include <stdlib.h>
#include <iostream>

extern Base *generate();
extern void identify(Base* p);
extern void identify(Base& r);

int main() {
  Base *rand = generate();
  Base *rand1 = generate();
  Base *rand2 = generate();

  identify(NULL);
  identify(rand1);
  identify(rand2);

  Base &ref = *rand;
  std::cout << std::endl;

  identify(ref);
  identify(*rand1);
  identify(*rand2);
  return 0;
}