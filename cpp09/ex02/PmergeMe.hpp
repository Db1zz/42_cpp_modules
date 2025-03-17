#ifndef P_MERGE_ME_HPP
# define P_MERGE_ME_HPP

#include <algorithm>
#include <cassert>
#include <functional>

template <class Container>
class PmergeMe {
public:
  PmergeMe();
  void sort(Container &numbers);

private:
typename Container::iterator binarySearch(
  typename Container::iterator first,
  typename Container::iterator last,
  int pair_size,
  int pair_value);

  bool isPairGreater(Container &main, long p1_start, long p2_start, long pair_size);

  void insertInterval(
    typename Container::iterator source_start,
    typename Container::iterator source_end,
    Container &dest,
    typename Container::iterator insert_pos,
    int interval_size);

  void insertPending(
    Container &new_main, const Container &pend, int pair_size);

  void sortPairs(Container &main, const long pair_size);

  int jacobsthalNumbers(int n);
};

template <class Container>
void PmergeMe<Container>::sort(Container &numbers) {
  if (numbers.size() <= 1) {
    return ;
  } 
  sortPairs(numbers, 1);
}

template <typename Container>
typename Container::iterator PmergeMe<Container>::binarySearch(
  typename Container::iterator first,
  typename Container::iterator last,
  int pair_size,
  int pair_value)
{
  if (pair_value > *(last - 1)) {
    return last;
  } else if (*(first + pair_size - 1) > pair_value) {
    return first;
  }

  int result_index = 0;

  int high_pair = (last - first) / pair_size - 1;
  int low = 0;
  int mittel;

  while (low <= high_pair) {
    mittel = low + (high_pair - low) / 2;
    int value = *(first + pair_size - 1 + (mittel * pair_size));

    if (pair_value > value) {
      result_index = mittel + 1;
      low = mittel + 1;
    } else if (pair_value < value) {
      high_pair = mittel - 1;
    } else {
      break;
    }
  }

  if (result_index == 0) {
    ++result_index;
  }

  return first + (result_index * pair_size);
}

template <class Container>
bool PmergeMe<Container>::isPairGreater(
  Container &main, long p1_start, long p2_start, long pair_size)
{
  if (!(p1_start + pair_size - 1 < static_cast<long>(main.size()))
    || !(p2_start + pair_size - 1 < static_cast<long>(main.size())))
  {
    return false;
  }
  return (main[p1_start + pair_size - 1] > main[p2_start + pair_size - 1]);
}

template <class Container>
void PmergeMe<Container>::insertInterval(
  typename Container::iterator source_start,
  typename Container::iterator source_end,
  Container &dest,
  typename Container::iterator insert_pos,
  int interval_size)
{
  assert(source_end >= source_start);
  assert(dest.end() >= insert_pos);
  int i = dest.end() - insert_pos;

  while (source_start + interval_size <= source_end) {
    dest.insert(dest.begin() + i, source_start, source_start + interval_size);
    source_start += interval_size * 2;
    i += interval_size;
  }
}

template <class Container>
void PmergeMe<Container>::insertPending(
  Container &new_main, const Container &pend, int pair_size)
{
  typedef typename Container::iterator IT;

  int jacobsthal_index = 2;
  int jacobstahl_current = jacobsthalNumbers(jacobsthal_index);

  int pend_start = pair_size - 1;
  int pend_end = -1;

  while (jacobstahl_current - 2 <= static_cast<long>(pend.size()) / pair_size) {
    for (int i = pend_start; i > pend_end; i -= pair_size, pend_start += pair_size) {
      assert((pair_size == 1 || i % pair_size != 0));

      IT it = binarySearch<Container>(
        new_main.begin(),
        new_main.end(),
        pair_size,
        pend[i]
      );

      assert(i - pair_size + 1 >= 0);
      assert(i + 1 <= static_cast<long>(pend.size()));
      new_main.insert(it, pend.begin() + i - pair_size + 1, pend.begin() + i + 1);
    }
    pend_end = pend_start;
    jacobstahl_current = jacobsthalNumbers(++jacobsthal_index);
  }

  for (int i = pend_start; i < static_cast<long>(pend.size()); i += pair_size) {
    IT it = binarySearch<Container>(new_main.begin(), new_main.end(), pair_size, pend[i]);
    new_main.insert(it, pend.begin() + i - pair_size + 1, pend.begin() + i + 1);
  }
}

template <class Container>
void PmergeMe<Container>::sortPairs(Container &main, const long pair_size) {
  const long size = (long)main.size();
  const long pair_amount = size / pair_size;

  if (pair_amount < 2) {
    return;
  }
  for (long i = 0; i + pair_size < size; i += pair_size * 2) {
    if (isPairGreater(main, i, i + pair_size, pair_size)) {
      std::swap_ranges(main.begin() + i, main.begin() + i + pair_size, main.begin() + i + pair_size);
    }
  }
  sortPairs(main, pair_size * 2);

  if (main.size() / pair_size < 3) {
    return;
  }

  Container new_main;
  Container pend;
  Container odd;

  new_main.insert(new_main.begin(), main.begin(), main.begin() + pair_size);
  insertInterval(main.begin() + pair_size, main.end(), new_main, new_main.begin(), pair_size);
  insertInterval(main.begin() + pair_size * 2, main.end(), pend, pend.begin(), pair_size);
  odd.insert(odd.begin(), main.begin() + main.size() - main.size() % pair_size, main.end());

  insertPending(new_main, pend, pair_size);

  main = new_main;
  main.insert(main.end(), odd.begin(), odd.end());
}

template<class Container>
int PmergeMe<Container>::jacobsthalNumbers(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = b + 2 * a;
        a = b;
        b = c;
    }
    return b;
}

#endif  // P_MERGE_ME_HPP
