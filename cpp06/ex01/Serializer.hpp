#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>

class Serializer {
public:
  struct Data {
    int value_;

    Data() : value_(0) {}
    Data(int value) : value_(value) {}
  };

  static uintptr_t Serialize(Data *ptr);
  static Data *Deserialize(uintptr_t raw);

private:
  Serializer();
  ~Serializer();
};

#endif  // SERIALIZER_HPP