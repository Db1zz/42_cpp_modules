#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <cstddef> // #include <stddef.h>

/*
  Before implementing anything read this dolbayob na goshe:

  https://en.cppreference.com/w/cpp/container/stack#:~:text=The%20standard%20containers%20std%3A%3A,std%3A%3Adeque%20is%20used.
  https://en.cppreference.com/w/cpp/container/deque

  Vivody sdelany:
  Stack based on std::deque contianer which has iterators, so we simply can use them.
*/

template <typename T>
class MutantStack : public std::stack<T> {
public:
  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef typename std::stack<T>::container_type::const_iterator const_iterator;

  // typedef struct iterator {
  //   /* Pre-defined types which are used by iterator */
  //   using value_type = T;
  //   using pointer = T*;
  //   using reference = T&;
  //   using difference_type = std::ptrdiff_t;
  //   using iterator_category = std::random_access_iterator_tag;

  //   iterator(std::ptrdiff_t ptr)
  //     : ptr_(ptr) {}

  //   /* Overloaded operators */
  //   reference operator*() const {
  //     return *ptr_;
  //   }

  //   pointer operator->() const {
  //     return ptr_;
  //   }

  //   iterator &operator++() {
  //     ++ptr;
  //     return *this;
  //   }

  //   iterator operator++(int) {
  //     iterator copy = *this;
  //     ++ptr_;
  //     return copy;
  //   }

  //   iterator &operator--() {
  //     --ptr_;
  //     return *this;
  //   }

  //   iterator operator--(int) {
  //     iterator copy = *this;
  //     ++ptr_;
  //     return copy;
  //   }

  //   bool operator==(const iterator &it) {
  //     return ptr_ == it.ptr_;
  //   }

  //   bool operator!=(const iterator &it) {
  //     return ptr_ != it.ptr_;
  //   }

  //   bool operator>=(const iterator &it) {
  //     return ptr_ >= it.ptr_;
  //   }
    
  //   bool operator<=(const iterator &it) {
  //     return ptr_ <= it.ptr_;

  //   }

  //   bool operator>(const iterator &it) {
  //     return ptr_ > it.ptr_;
  //   }
    
  //   bool operator<(const iterator &it) {
  //     return ptr_ < it.ptr_;
  //   }

  //   iterator &operator=(const iterator &to_copy) {
  //     ptr_ = to_copy.ptr_;
  //     return *this;
  //   }

  //   iterator &operator=(const iterator &to_copy) {
  //     ptr_ = to_copy.ptr_;
  //     return *this;
  //   }

  //   iterator &operator+(const iterator &n) {
  //     iterator copy = *this;
  //     copy.ptr_ += n.ptr_;
  //     return copy;
  //   }

  //   iterator &operator+(const difference_type &n) {
  //     iterator copy = *this;
  //     copy.ptr_ += n;
  //     return copy;
  //   }

  //   iterator &operator-(const iterator &n) {
  //     iterator copy = *this;
  //     copy.ptr_ -= n.ptr_;
  //     return copy;
  //   }

  //   iterator &operator-(const difference_type &n) {
  //     iterator copy = *this;
  //     copy.ptr_ -= n;
  //     return copy;
  //   }
  //   pointer ptr_;
  // }

  iterator begin() {
    return this->c.begin();
  }

  iterator end() {
    return this->c.end();
  }

  const_iterator begin() const {
    return this->c.begin();
  }

  const_iterator end() const {
    return this->c.end();
  }
};

#endif  // MUTANTSTACK_HPP
