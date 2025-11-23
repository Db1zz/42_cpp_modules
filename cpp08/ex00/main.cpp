#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

template <typename T, typename U>
T &operator<<(T &v, const U &item) {
  v.push_back(  item);
  return v;
}

template <typename T, typename U>
T &operator,(T &v, const U &item) {
  v.push_back(item);
  return v;
}

int main() {
  std::vector<int> vector; vector << 0, 1, 2, 3, 4;
  std::list<int> list; list << 0, 1, 2, 3, 4;
  std::deque<int> deque; deque << 0, 1, 2, 3, 4;

  int to_find1 = 4;
  int to_find2 = 5;

  try {
    easyfind(list, to_find1);
    easyfind(deque, to_find1);
    easyfind(vector, to_find1);

    // These easyfind() calls should throw an exception.
    easyfind(list, to_find2);
    // easyfind(deque, to_find2);
    // easyfind(vector, to_find2);
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
  return 0;
}