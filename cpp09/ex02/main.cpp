#include "ParserError.hpp"
#include "parser.hpp"

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

void display_matrix(const std::vector<std::vector<int> > &array) {
  std::cout << "[";
  for (size_t i = 0; i < array.size(); i++) {
    for (size_t j = 0; j < array[i].size(); j++) {
      std::cout << array[i][j] << ", ";
    }
  }
  std::cout << "]" << std::endl;
}

int jacobsthal_numbers(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = b + 2 * a;
        a = b;
        b = c;
    }
    return b;
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

void insert_pending(
  std::vector<std::vector<int> > &new_main,
  const std::vector<std::vector<int> > &pend)
{
  typedef std::vector<std::vector<int> >::iterator IT;

  int j = 1;

  int start = jacobsthal_numbers(j - 1);
  int end = jacobsthal_numbers(j);

  int dif = end - start;

  int pend_index = 0;
  int index = 0;

  while (end + dif < static_cast<int>(new_main.size())) {
    for (int i = pend_index; i < pend_index + dif && i < pend.size(); ++i) {
      IT it = std::upper_bound(
        new_main.begin(),
        new_main.end(),
        pend[i],
        comp_upper
      );
      new_main.insert(it, pend[i]);
    }
    pend_index += dif;
    index = end;
    start = end;
    end = jacobsthal_numbers(++j);
    dif = end - start;
    display_matrix(new_main);
  }

  while (index < static_cast<long>(pend.size())) {
    IT it = std::upper_bound(new_main.begin(), new_main.end(), pend[index], comp_upper);
    new_main.insert(it, pend[index]);
    ++index;
  }
}

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

  std::vector<std::vector<int> > new_main;
  std::vector<std::vector<int> > pend;
  std::vector<int> odd_pair;
  
  std::copy(main.begin(), main.begin() + pair_size, std::back_inserter(odd_pair));

  new_main.push_back(odd_pair);
  copy_interval(main, new_main, pair_size, pair_size);
  copy_interval(main, pend, pair_size, pair_size * 2);

  insert_pending(new_main, pend);

  copy(new_main, main);
}

void merge_insertion_sort(std::vector<int> &numbers) {
  if (numbers.size() <= 1) {
    return ;
  } 
  sort_pairs(numbers, 1);
}

bool greater(std::vector<int>::iterator a, std::vector<int>::iterator b) {
  return *a >= *b;
}

bool is_sorted(std::vector<int>::iterator start, std::vector<int>::iterator end) {
  while (start + 1 < end && greater(start + 1, start)) {
    ++start;
  }
  if (start + 1 != end) {
    std::cout << "Error: " << *start << std::endl;
  }
  return start + 1 == end;
}

int main(int ac, const char **av) {
  std::vector<int> input_numbers;

  try {
    parse_input(av + 1, ac - 1, input_numbers);
  } catch (const ParserError &e) {
    std::cerr << "Error: " << std::endl;
    e.displayError();
    return EXIT_FAILURE;
  } catch (const std::runtime_error &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "Before: "; display_array(input_numbers);

  merge_insertion_sort(input_numbers);
  std::cout << "After: "; display_array(input_numbers);
  if (is_sorted(input_numbers.begin(), input_numbers.end())) {
    std::cout << "DA\n";
  }
  return EXIT_SUCCESS;
}