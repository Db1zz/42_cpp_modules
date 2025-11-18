#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stdlib.h>
#include <exception>

template <typename T>
class Array {
public:
  Array(unsigned int n = 0);
  Array(const Array<T> &copy);
  Array<T> &operator=(const Array<T> &to_copy);
  ~Array();

  unsigned int size() const;
  T &operator[](unsigned int index);

private:
  T *data_;
  unsigned int size_;
};

template <typename T>
Array<T>::Array(unsigned int n)
  : data_(NULL), size_(n)
{
  std::cout << "Default Array constructor called" << std::endl;
  if (size_ > 0) {
    data_ = new T[n];
  }
}

template<typename T>
Array<T>::Array(const Array<T> &copy)
  : data_(NULL), size_(0)
{
  std::cout << "Array copy constructor called" << std::endl;
  *this = copy;
}

template<typename T>
Array<T>::~Array() {
  std::cout << "Array destructor called" << std::endl;
  if (data_) {
    delete[] data_;
  }
}

template<typename T>
unsigned int Array<T>::size() const {
  return size_;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &to_copy) {
  std::cout << "Array copy asignment operator called" << std::endl;
  if (this != &to_copy) {
    if (data_ == NULL) {
      delete[] data_;
    }
    data_ = new T[to_copy.size_];
    size_ = to_copy.size_;
    for (unsigned int i = 0; i < to_copy.size_; i++) {
      data_[i] = to_copy.data_[i];
    }
  }
  return *this;
}

template<typename T>
T &Array<T>::operator[](unsigned int index) {
  if (index >= size_) {
    throw std::runtime_error("Index is out of bounds");
  }
  return data_[index];
}

#endif  // ARRAY_HPP