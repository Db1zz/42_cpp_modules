#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

void display_array(const std::vector<int> &array) {
  std::cout << "[";

  if (array.size()) {
    size_t index = 0;
    size_t size = array.size() - 1;

    while (index < size) {
      std::cout << array[index] << ", ";
      ++index;
    }
    std::cout << array[index];
  }
  std::cout << "]" << std::endl;
}

/*
  https://en.wikipedia.org/wiki/Jacobsthal_number
*/
int jacobsthal_numbers(int n) {
  if (n == 1) {
    return 1;
  } else if (n == 0) {
    return 0;
  }
  return jacobsthal_numbers(n - 1) + 2 * jacobsthal_numbers(n - 2);
}

/*
  https://warwick.ac.uk/fac/sci/dcs/teaching/material-archive/cs341/fj.pdf
*/
std::vector<int> merge_insertion_sort(const std::vector<int> &numbers)
{
  std::vector<int> sorted_vector;
  std::vector<int> main;


  /*
    Check if this one was sorted.w
  */
  sorted_vector = main;
  return sorted_vector;
}

bool is_greater(const std::vector<int> &a, const std::vector<int> &b) {
  assert(a.size() == b.size() && "Size is not the same.");

  return (a[a.size() - 1] > b[b.size() - 1]);
}

std::vector<int> *create_pairs(const std::vector<int> &main, size_t pair_size) {
  if (main.size() <= 1) {
    return NULL;
  }

  bool is_array_odd = main.size() % 2 == 0;
  size_t size = main.size() - is_array_odd;
  std::vector<std::vector<int>> a; // a is greater
  std::vector<std::vector<int>> b; // b is less than a
  std::vector<int> remainder; // odd pair
  size_t i = 0;

  // implement pair_size
  while (i < size) {
    a.push_back(std::vector<int>(main.begin() + i, main.begin() + i + pair_size));
    b.push_back(std::vector<int>(main.begin() + i, main.begin() + i + pair_size));
  }

  if (!is_array_odd) {
    remainder.push_back(std::vector<int>(main.begin() + i, main.begin() + main.size() - 1));
  }


}

void sort_pairs(std::vector<int> &main, std::vector<int> a, std::vector<int> b) {

  sort_pairs(main, a, b);
}

int main() {
  std::vector<int> input;
  merge_insertion_sort({11, 3, 65, 1, 2, 8, 10, 5, 4, 8});
  std::cout << jacobsthal_numbers(2) << std::endl;
}