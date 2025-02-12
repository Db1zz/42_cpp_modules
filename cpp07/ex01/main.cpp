#include "iter.hpp"
#include <iostream>

class Cont {
public:
  Cont() : val_(sInst_++) {}
  int get() const {return val_;}

private:
  static int sInst_;
  int val_;
};

int Cont::sInst_ = 0;

std::ostream &operator<<(std::ostream &o, const Cont &cl) {
  o << cl.get();
  return o;
}

template<typename T>
void print(const T &x) {
  std::cout << x << std::endl;
  return;
}

int main() {
  int arr1[] = {0,1,2,3,4};
  Cont arr2[5];

  iter(arr1, 5, print);
  iter<int>(NULL, 0, NULL);
  iter(arr2, 5, print);
}