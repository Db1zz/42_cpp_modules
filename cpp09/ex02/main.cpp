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
  with each recursion level we have to multiple amount of pairs by 2,
    and do it untill we gonna reach this statement: pairs_amount = size / pair_size == 0

  pair_size = 2;
  size == 10 / pair_size = 5; // 5 == amount of pairs
  2,11 0,17 8,16 6,15 3,10
*/
bool is_pair_greater(std::vector<int> &main, long p1_start, long p2_start, long pair_size) {
  if (!(p1_start + pair_size - 1 < static_cast<long>(main.size()))
    || !(p2_start + pair_size - 1 < static_cast<long>(main.size())))
  {
    return false;
  }
  return (main[p1_start + pair_size - 1] > main[p2_start + pair_size - 1]);
}

template <typename T>
void copy_interval(
  const T &src, T &dest, long interval_size, bool start_from_interval)
{
  const long size = src.size();
  long i = 0;

  if (start_from_interval) {
    i += interval_size;
  }
  while (i + interval_size <= size) {
    std::cout << i << std::endl;
    std::copy(src.begin() + i, src.begin() + i + interval_size, std::back_inserter(dest));
    i += interval_size * 2;
  }
}

/*
  References:
    https://warwick.ac.uk/fac/sci/dcs/teaching/material-archive/cs341/fj.pdf
    https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91 
*/
void sort_pairs(std::vector<int> &main, const long pair_size) {
  const long size = (long)main.size();
  const long pair_amount = size / pair_size;

  if (pair_amount < 2) {
    return;
  }
  for (long i = 0; i + pair_size < size; i += pair_size * 2) {
    if (is_pair_greater(main, i, i + pair_size, pair_size)) {
      std::swap_ranges(main.begin() + i, main.begin() + i + pair_size, main.begin() + i + pair_size);
    }
  }
  sort_pairs(main, pair_size * 2);

  int perv = 1;
  std::vector<int> new_main; // b0 + a0...ax
  std::vector<int> pend; // b1 + bx

  while (true) {

  }
}

void merge_insertion_sort(std::vector<int> &numbers)
{
  if (numbers.size() <= 1) {
    return ;
  } 
  sort_pairs(numbers, 1);
  display_array(numbers);
}

int main(int ac, char **av) {
  const long size = 22;
  int numbers[] = {11,2, 17,0, 16,8, 6,15, 10,3, 21,1, 18,9, 14,19, 12,5, 20,4, 13,7};
  std::vector<int> input(&numbers[0], &numbers[size]);
  merge_insertion_sort(input);

  // std::vector<int> dest;
  // copy_interval(input, dest, 4, true);
  // display_array(dest);
  return 0;
}