#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
public:
  Point();
  Point(float x, float y);
  ~Point();
  Point operator=(const Point& point);
  float getX() const;
  float getY() const;

private:
  const Fixed _x;
  const Fixed _y;
};

#endif  // POINT_HPP