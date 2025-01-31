#include "Point.hpp"
#include "Fixed.hpp"

Point::Point()
  : _x(0), _y(0) {};

Point::Point(float x, float y) 
  : _x(x), _y(y) {}

Point::~Point() {}

Point Point::operator=(const Point& point) {
  return Point(point.getX(), point.getY());
}

float Point::getX() const {
  return _x.toFloat();
}

float Point::getY() const {
  return _y.toFloat();
}
