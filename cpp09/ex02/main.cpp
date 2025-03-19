#include "ParserError.hpp"
#include "parser.hpp"
#include "PmergeMe.hpp"
#include "Timer.hpp"

#include <iostream>
#include <cstdlib>
#include <algorithm>

#include <vector>
#include <deque>

template <class Container>
void display_array(const Container &array) {
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

template<class Container1, class Container2>
bool compare_containers(Container1 &v1, Container2 &v2) {
  if (v1.size() != v2.size()) {
    return false;
  }

  long size = v1.size();
  for (int i = 0; i < size; ++i) {
    if (v1[i] != v2[i]) {
      return false;
    }
  }

  return true;
}

#include <sys/time.h>

template <class Container>
void measure_sorting_efficiency(Container &to_sort, const std::string &container_name)
{
  Timer timer;

  timer.start();
  PmergeMe<Container>::sort(to_sort);
  timer.stop();

  time_t seconds = timer.getSeconds();
  time_t milliseconds = timer.getMiliseconds();
  time_t microseconds = timer.getMicroseconds();

  std::cout << "Time to process a range of " << to_sort.size()
            << " elements with " << container_name << " : "
            << seconds << ":" << milliseconds << ":" << microseconds << std::endl;
}

int main(int ac, const char **av) {
  std::vector<int> input_numbers;
  std::vector<int> sort_with_stl;
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

  sort_with_stl = input_numbers;
  std::sort(sort_with_stl.begin(), sort_with_stl.end());

  std::vector<int> sort_vector_with_jacobsthal(input_numbers);
  std::deque<int> sort_deque_with_jacobsthal(input_numbers.begin(), input_numbers.end());


  std::cout << "Before: "; display_array(input_numbers);
  std::cout << "After: "; display_array(sort_with_stl);
  measure_sorting_efficiency(sort_vector_with_jacobsthal, "std::vector");
  measure_sorting_efficiency(sort_deque_with_jacobsthal, "std::deque");

  // {
  //   PmergeMe<std::vector<int> >::sort(sort_with_jacobsthal);
  //   std::cout << "After: "; display_array(sort_with_jacobsthal);
  //   if (compare_containers(sort_with_jacobsthal, sort_with_stl)) {
  //     std::cout << "Цитата Папича: \"0 ошибок как всегда\"\n";
  //   }
  // }
  // {
  //   PmergeMe<std::deque<int> >::sort(sort_with_jacobsthal);
  //   std::cout << "After: "; display_array(sort_with_jacobsthal);
  //   if (compare_containers(sort_with_jacobsthal, sort_with_stl)) {
  //     std::cout << "Цитата Папича: \"0 ошибок как всегда\"\n";
  //   }
  // }

  return EXIT_SUCCESS;
}