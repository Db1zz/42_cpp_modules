#include "Point.hpp"
#include <iostream>

extern bool bsp(Point const& a, Point const& b, Point const& c, Point const& point);

int main(void) {
  if (bsp(Point(0,1), Point(3,4), Point(0,4), Point(1,3))) {
    std::cout << "Yay point is inside of the triangle!\n";
  } else {
    std::cout << "scheiseee its ouside wtf\n";
  }
  return 0;
}
