#include "A.hpp"
#include <iostream>

A::A() {
  std::cout << "A default construcor has been called\n";
}

A::~A() {
  std::cout << "A destructor has been called\n";
}