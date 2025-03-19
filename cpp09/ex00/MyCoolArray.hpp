#ifndef MY_COOL_ARRAY_HPP
# define MY_COOL_ARRAY_HPP

#include <cstdlib>

template <typename T>
class MyCoolArray {
public:
  MyCoolArray();
  MyCoolArray(const MyCoolArray &to_copy);
  ~MyCoolArray();
  MyCoolArray &operator=(const MyCoolArray &to_copy);
  T &operator[](int index);

  void pushBack(T value);
  size_t size() const;


private:
  void realloc();
  void copy(T *dest, const T *src);

  size_t reserved_;
  size_t size_;
  T *data_;
};

template <typename T>
MyCoolArray<T>::MyCoolArray()
  : size_(0), reserved_(5)
{
  realloc();
}

template <typename T>
MyCoolArray<T>::~MyCoolArray() {
  if (data_) {
    delete[] data_;
    data_ = NULL;
  }
}

template <typename T>
MyCoolArray<T>::MyCoolArray(const MyCoolArray &to_copy) {
  *this = to_copy;
}

template <typename T>
MyCoolArray<T> &MyCoolArray<T>::operator=(const MyCoolArray &to_copy) {
  if (this != &to_copy) {
    delete[] this->data_;
    this->reserved_ = to_copy.reserved_;
    this->size_ = to_copy.size_;
    this->data_ = new int[reserved_];
    copy(this->data_, to_copy.data_);
  }
  return *this;
}

template <typename T>
T &MyCoolArray<T>::operator[](int index) {
  return data_[index];
}

template <typename T>
void MyCoolArray<T>::pushBack(T value) {
  if (size_ == reserved_) {
    realloc();
  }
  data_[size_++] = value;
}

template <typename T>
size_t MyCoolArray<T>::size() const {
  return size_;
}

template <typename T>
void MyCoolArray<T>::realloc() {
  int *temp = NULL;

  reserved_ *= 2;
  temp = new int[reserved_];

  if (data_ != NULL) {
    copy(temp, data_);
    delete[] data_;
  }

  data_ = temp;
}

template <typename T>
void MyCoolArray<T>::copy(T *dest, const T *src) {
  for (int i = 0; i < size_; ++i) {
    dest[i] = src[i];
  }
}

#endif  // MY_COOL_ARRAY_HPP