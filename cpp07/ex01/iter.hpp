#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void iter(const T *arr, int length, void(*func)(const T&)) {
  if (arr == NULL || length == 0 || func == NULL) {
    return;
  }

  for (int i = 0; i < length; i++) {
    func(arr[i]);
  }
}

#endif  // ITER_HPP