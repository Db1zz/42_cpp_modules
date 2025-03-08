#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include "Error.hpp"
#include "parser.hpp"

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

void display_matrix(const std::vector<std::vector<int> > &array) {
  std::cout << "[";
  for (size_t i = 0; i < array.size(); i++) {
    for (size_t j = 0; j < array[i].size(); j++) {
      std::cout << array[i][j] << ", ";
    }
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

bool is_pair_greater(std::vector<int> &main, long p1_start, long p2_start, long pair_size) {
  if (!(p1_start + pair_size - 1 < static_cast<long>(main.size()))
    || !(p2_start + pair_size - 1 < static_cast<long>(main.size())))
  {
    return false;
  }
  return (main[p1_start + pair_size - 1] > main[p2_start + pair_size - 1]);
}

template <typename Numbers, typename Matrix>
void copy_interval(
  const Numbers &src, Matrix &dest, long interval_size, long start)
{
  const long size = src.size();
  long i = start;

  while (i + interval_size <= size) {
    Numbers interval;
    std::copy(src.begin() + i, src.begin() + i + interval_size, std::back_inserter(interval));
    dest.push_back(interval);
    i += interval_size * 2;
  }
}

bool comp_upper(
  const std::vector<int> &v1,
  const std::vector<int> &v2)
{
  return v1[v1.size() - 1] < v2[v2.size() - 1];
}

template <typename Cont, typename ContMatrix>
void copy(const ContMatrix &src, Cont &dest) {
  size_t dest_index = 0;

  for (size_t i = 0; i < src.size(); ++i) {
    std::copy(src[i].begin(), src[i].end(), dest.begin() + dest_index);
    dest_index += src[i].size();
  }
}

/*
  References:
    https://warwick.ac.uk/fac/sci/dcs/teaching/material-archive/cs341/fj.pdf
    https://dev.to/emuminov/human-explanation-and-step-by-step-visualisation-of-the-ford-johnson-algorithm-5g91 
*/
void sort_pairs(std::vector<int> &main, const long pair_size) {
  typedef std::vector<std::vector<int> >::iterator IT;

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

  // b0 + (a0...ax)
  std::vector<std::vector<int> > new_main;
  std::vector<int> tmp;
  
  // (b0...bx] b0 is excluded e.g: (b1...bx)
  std::vector<std::vector<int> > pend;

  std::copy(main.begin(), main.begin() + pair_size, std::back_inserter(tmp));
  new_main.push_back(tmp);
  copy_interval(main, new_main, pair_size, pair_size);
  copy_interval(main, pend, pair_size, pair_size * 2);

  long perv = 1;
  long curr = 3;
  long index = 0;
  while (curr - perv + perv - 2 < static_cast<long>(pend.size())) {
    for (long i = curr - perv + perv - 2; i >= perv - 1; --i) {
      IT it = std::upper_bound(
        new_main.begin(),
        new_main.begin() + curr - perv + perv - 1,
        pend[i],
        comp_upper);
      new_main.insert(it, pend[i]);
    }
    perv = curr;
    index = perv - 1;
    curr = jacobsthal_numbers(curr + 1);
  }
  while (index < static_cast<long>(pend.size())) {
    IT it = std::upper_bound(new_main.begin(), new_main.end(), pend[index], comp_upper);
    new_main.insert(it, pend[index]);
    ++index;
  }

  copy(new_main, main);
}

void merge_insertion_sort(std::vector<int> &numbers) {
  if (numbers.size() <= 1) {
    return ;
  } 
  sort_pairs(numbers, 1);
  display_array(numbers);
}

int main(int ac, const char **av) {
  std::vector<int> input_numbers;

  try {
    parse_input(av + 1, ac - 1, input_numbers);
  } catch (const Error &e) {
    std::cerr << "Error: " << std::endl;
    display_error(e);
    return EXIT_FAILURE;
  } catch (const std::runtime_error &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  display_array(input_numbers);
  merge_insertion_sort(input_numbers);
  return 0;
} 