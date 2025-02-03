#include "ScalarConverter.hpp"
#include <iostream>
#include <float.h>
#include <limits.h>
#include <limits>

/*
  INT_MAX = 2147483647 - should fail
  t1 = 42.21
  t2 = 42.99999999999999999
  1.7976931348623157e+308
*/

int main() {
  ScalarConverter::Convert("-inf");
  return 0;
}