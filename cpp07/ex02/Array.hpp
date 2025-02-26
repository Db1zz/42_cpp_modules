#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdlib.h>
#include <exception>

template <typename T>
class Array {
public:
  Array(u_int32_t n = 0)
    : data_(NULL), size_(n)
  {
    std::cout << "Default Array constructor called" << std::endl;
    if (size_ > 0) {
      data_ = new int[n];
      if (!data_) {
        return;
      }
      for (u_int32_t i = 0; i < size_; i++) {
        data_[i] = 0;
      }
    }
  }

  Array(const Array<T> &copy)
    : data_(NULL), size_(0)
  {
    std::cout << "Array copy constructor called" << std::endl;
    *this = copy;
  }

  ~Array() {
    std::cout << "Array destructor called" << std::endl;
    if (data_) {
      delete[] data_;
    }
  }

  u_int32_t size() const {return size_;}

  Array<T> &operator=(const Array<T> &to_copy) {
    std::cout << "Array copy asignment operator called" << std::endl;
    if (this != &to_copy) {
      if (data_ == NULL) {
        delete[] data_;
      }
      data_ = new T[to_copy.size_];
      size_ = to_copy.size_;
      for (u_int32_t i = 0; i < to_copy.size_; i++) {
        data_[i] = to_copy.data_[i];
      }
    }
    return *this;
  }

  T &operator[](u_int32_t index) {
    if (index >= size_) {
      throw std::runtime_error("Index is out of bounds");
    }
    return data_[index];
  }

private:
  T *data_;
  u_int32_t size_;
};

#endif  // ARRAY_HPP