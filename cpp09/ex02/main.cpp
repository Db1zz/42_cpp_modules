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
    std::cout << i << std::endl;
    std::copy(src.begin() + i, src.begin() + i + interval_size, std::back_inserter(interval));
    dest.push_back(interval);
    i += interval_size * 2;
  }
}

template <typename T>
bool comp_upper(
  const T &v1, const T &v2)
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
template <typename Cont>
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

  int perv = 1;
  int curr = jacobsthal_numbers(perv + 1);
  std::vector<std::vector<int> > new_main; // b0 + a0...ax
  std::vector<int> tmp;
  std::vector<std::vector<int> > pend; // b1 + bx

  std::copy(main.begin(), main.begin() + pair_size, std::back_inserter(tmp));
  new_main.push_back(tmp);
  copy_interval(main, new_main, pair_size, pair_size);
  copy_interval(main, pend, pair_size, pair_size * 2);

  while (curr - perv < pend.size()) {
    perv = curr;

    /*
      i * pair_size - 1
    */
    /*
      curr == 2
      b1, b2, b3
      0   1   2

      b0, a0, a1, a2, a3
      0   1   2   3   4
    */
    for (int index = curr; index != perv; --index) {
      IT it = std::upper_bound(
        new_main.begin(),
        new_main.begin() + curr + 1,
        pend[curr],
        comp_upper<Cont>);
    }
    curr = jacobsthal_numbers(perv + 1);
  }
  for (size_t i = 0; i < pend.size(); ++i) {
    IT it = std::upper_bound(new_main.begin(), new_main.end(), pend[i], comp_upper<Cont>);
    new_main.insert(it, pend[i]);
  }

  // copy everything from new_main to main
  copy(new_main, main);
}

void merge_insertion_sort(std::vector<int> &numbers)
{
  if (numbers.size() <= 1) {
    return ;
  } 
  sort_pairs<std::vector<int> >(numbers, 1);
  display_array(numbers);
}

int main(int ac, char **av) {
  const long size = 8;
  int numbers[] = {11,2, 17,0, 16,8, 6,15};
  std::vector<int> input(&numbers[0], &numbers[size]);
  merge_insertion_sort(input);

  // std::vector<int> dest;
  // copy_interval(input, dest, 4, true);
  // display_array(dest);
  return 0;
}