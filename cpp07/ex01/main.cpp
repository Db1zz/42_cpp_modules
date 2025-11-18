#include "iter.hpp"

#include <iostream>
#include <string>

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
void print(T x) {
  std::cout << x << std::endl;
  return;
}

int main() {
  int arr1[] = {0,1,2,3,4};
  Cont arr2[5];
  std::string abobusi[5] = {"abobaMe4n1k", "abobaMag", "ob14n1yAboba", "abobaFlexer", "abobaShadowFiend"};

  iter(arr1, 5, print<int>);
  iter(arr2, 5, print<Cont>);
  iter(abobusi, 5, print<std::string>);
}