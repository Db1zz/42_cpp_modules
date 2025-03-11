#include "ParserError.hpp"
#include "parser.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <functional>

/*
  search = 5

  [0, 1, 2, 3, 4, 5, 6, 7]
  ^         ^            ^
  s         m            e
  start = 0
  end = 7
  mittel = start + (end - start / 2) == 3

  [0, 1, 2, 3, 4, 5, 6, 7]
                  ^     ^
                  sm    e
  start = 3
  end = 7
  mittel = start + (end - start / 2) == 5

  [0, 1, 2, 3, 4, 5, 6, 7]
                  ^  ^
                  sm e
  start = 5
  end = 6
  mittel = start + (end - start / 2) == 6

  [0, 1, 2, 3, 4, 5, 6, 7]
                  ^ 
                  sme
  start = 5
  end = 5
  mittel = start + (end - start / 2) == 5
*/

/*
  [0, 1, 2, 3, 4, 5, 6, 7]
  ^            ^        ^
  s            m        e
*/

template <typename Container>
typename Container::iterator binary_search(
  typename Container::iterator first,
  typename Container::iterator last,
  int pair_size,
  int pair_value)
{
  int result_index = 0;

  int high_pair = (last - first) / pair_size - 1;
  int low = 0;
  int mittel;

  while (low < high_pair) {
    mittel = low + (high_pair - low) / 2;
    int value = *(first + pair_size + (mittel * pair_size));

    if (pair_value >= value) {
      result_index = mittel * pair_size;
      low = mittel + 1;
    } else if (pair_value < value) {
      high_pair = mittel;
    } else {
      return first + result_index;
    }
  }
  return first + result_index;
}

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

template <typename Numbers>
void insert_interval(
  typename Numbers::iterator source_start,
  typename Numbers::iterator source_end,
  Numbers &dest,
  typename Numbers::iterator insert_pos,
  int interval_size)
{
  int i = dest.end() - insert_pos;

  while (source_start + interval_size <= source_end) {
    dest.insert(dest.begin() + i, source_start, source_start + interval_size);
    source_start += interval_size * 2;
    i += interval_size;
  }
}

bool comp_upper(
  const std::vector<int> &v1,
  const std::vector<int> &v2)
{
  return v1[v1.size() - 1] < v2[v2.size() - 1];
}

void insert_pending(std::vector<int> &new_main, const std::vector<int> &pend, int pair_size)
{
  typedef std::vector<int>::iterator IT;

  int j = 1;

  int start = jacobsthal_numbers(j - 1);
  int end = jacobsthal_numbers(j);

  int dif = end - start;

  int pend_index = 0;
  int index = 0;

  while ((end + dif) * pair_size < static_cast<int>(new_main.size())) {
    for (int i = pend_index; i < pend_index + dif * pair_size && i < pend.size(); i += pair_size) {
      IT it = binary_search<std::vector<int> >(
        new_main.begin(),
        new_main.end(),
        pair_size,
        pend[i]
      );
      new_main.insert(it, pend.begin() + i, pend.begin() + i + pair_size);
    }
    pend_index += dif * pair_size;
    index = end * pair_size;
    start = end;
    end = jacobsthal_numbers(++j);
    dif = end - start;
    display_array(new_main);
  }

  while (index < static_cast<long>(pend.size())) {
    IT it = binary_search<std::vector<int > >(new_main.begin(), new_main.end(), pair_size, pend[index]);
    new_main.insert(it, pend.begin() + index, pend.begin() + index + pair_size);
    index += pair_size;
  }
}

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

  std::vector<int> new_main;
  std::vector<int> pend;

  new_main.insert(new_main.begin(), main.begin(), main.begin() + pair_size);
  insert_interval(main.begin() + pair_size, main.end(), new_main, new_main.begin(), pair_size);
  insert_interval(main.begin() + pair_size * 2, main.end(), pend, pend.begin(), pair_size);

  std::cout << "PairSize: " << pair_size << std::endl;
  std::cout << "Pend: "; display_array(pend);
  std::cout << "NewMain: ";display_array(new_main);

  insert_pending(new_main, pend, pair_size);

  main = new_main;
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
  // std::vector<int> input_numbers;

  // try {
  //   parse_input(av + 1, ac - 1, input_numbers);
  // } catch (const ParserError &e) {
  //   std::cerr << "Error: " << std::endl;
  //   e.displayError();
  //   return EXIT_FAILURE;
  // } catch (const std::runtime_error &e) {
  //   std::cerr << "Error: " << e.what() << std::endl;
  //   return EXIT_FAILURE;
  // }

  // std::cout << "Before: "; display_array(input_numbers);

  // merge_insertion_sort(input_numbers);
  // std::cout << "After: "; display_array(input_numbers);
  // if (is_sorted(input_numbers.begin(), input_numbers.end())) {
  //   std::cout << "DA\n";
  // }

  // return EXIT_SUCCESS;

  int size = 8;
  int temp[8] = {0, 1, 2, 3, 4, 5, 6, 7};

  std::vector<int> vec(&temp[0], &temp[size]);
  display_array(vec);

  std::vector<int>::iterator it = binary_search<std::vector<int> >(vec.begin(), vec.end(), 2, 7);

  if (it < vec.end()) {
      std::cout << "Result: " << *it << std::endl;
  }

  return 0;
}