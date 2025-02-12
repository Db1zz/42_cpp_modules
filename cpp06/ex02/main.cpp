#include "A.hpp"
#include "C.hpp"
#include "B.hpp"
#include "Base.hpp"
#include <stdlib.h>

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
  return 0;
}