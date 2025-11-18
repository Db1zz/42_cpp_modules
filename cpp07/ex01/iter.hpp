#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *arr, size_t size, const F function) {
  if (arr == NULL || size == 0 || function == NULL) {
    return;
  }

  for (size_t i = 0; i < size; ++i) {
    function(arr[i]);
  }
}

#endif  // ITER_HPP