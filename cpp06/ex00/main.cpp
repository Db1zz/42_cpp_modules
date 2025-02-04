#include "ScalarConverter.hpp"
#include <iostream>
#include <float.h>
#include <limits.h>
#include <limits>
#include <math.h>

/*
  INT_MAX = 2147483647 - should fail
  t1 = 42.21
  t2 = 42.99999999999999999
  DBL_MAX = 1.7976931348623157e+308
  1.7976931348623157e+1000 = inf
  -nan nan +nan -inf inf +inf*/

int main(int ac, char **av) {
  if (ac == 2) {
    ScalarConverter::Convert(av[1]);
  }
  return 0;
}
