#include "Serializer.hpp"
#include <iostream>

int main() {
  Serializer::Data data(5);

  uintptr_t p = Serializer::Serialize(&data);
  Serializer::Data *dp = Serializer::Deserialize(p);

  if (dp) {
    std::cout << dp->value_ << std::endl;
    std::cout << dp << std::endl;
    std::cout << &data << std::endl;
  }
  return 0;
}