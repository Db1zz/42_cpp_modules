#include "Point.hpp"
#include <cmath>
#include <iostream>

static float cross_product(Point const& a, Point const& b, Point const& p) {
  return (b.getX() - a.getX()) * (p.getY() - a.getY()) -
         (b.getY() - a.getY()) * (p.getX() - a.getX());
}

bool bsp(Point const& a, Point const& b, Point const& c, Point const& point) {
  float ab = cross_product(a, b, point);
  float bc = cross_product(b, c, point);
  float ca = cross_product(c, a, point);

  bool all_positive = (ab >= 0 && bc >= 0 && ca >= 0);
  bool all_negative = (ab <= 0 && bc <= 0 && ca <= 0);

  return all_positive || all_negative;
}
