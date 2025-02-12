#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdlib.h>
#include <exception>

template <typename T>
class Array {
public:
  Array() : data_(NULL), size_(0) {}
  Array(uint32_t n) {
      data_ = new int[n];
      if (!data_) {
        return;
      }
      for (uint32_t i = 0; i < n; i++) {
        data_[i] = 0;
      }
      size_ = n;
  }

  Array(const Array<T> &copy) {
    *this = copy;
  }

  ~Array() {
    if (data_) {
      delete[] data_;
    }
  }

  uint32_t size() const {return size_;}

  class IndexOutOfBounds : public std::exception {
    public:
      const char *what() const throw() {
        return "Index is out of bounds";
      }
  };

  Array<T> &operator=(const Array<T> &to_copy) {
    if (this == &to_copy) {
      return *this;
    } else if (data_ == NULL) {
      delete[] data_;
    }
    data_ = new T[to_copy.size_];
    size_ = to_copy.size_;
    for (uint32_t i = 0; i < to_copy.size_; i++) {
      data_[i] = to_copy.data_[i];
    }
    return *this;
  }

  T &operator[](int64_t index) {
    if (!(size_ > 0 && index < size_)) {
      throw Array::IndexOutOfBounds();
    }
    return data_[index];
  }

private:
  T *data_;
  uint32_t size_;
};

#endif  // ARRAY_HPP