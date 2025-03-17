#include "ParserError.hpp"
#include "parser.hpp"
#include "PmergeMe.hpp"

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

  PmergeMe<std::vector<int> > sort_vector;
  PmergeMe<std::deque<int> > sort_deque;

  std::cout << "Before: "; display_array(input_numbers);

  {
    std::vector<int> sort_with_jacobsthal(input_numbers);

    sort_vector.sort(sort_with_jacobsthal);
    std::cout << "After: "; display_array(sort_with_jacobsthal);
    if (compare_containers(sort_with_jacobsthal, sort_with_stl)) {
      std::cout << "Цитата Папича: \"0 ошибок как всегда\"\n";
    }
  }
  // {
  //   std::deque<int> sort_with_jacobsthal(input_numbers.begin(), input_numbers.end());
  //   sort_deque.sort(sort_with_jacobsthal);
  //   if (compare_containers(sort_with_jacobsthal, sort_with_stl)) {
  //     std::cout << "Цитата Папича: \"0 ошибок как всегда\"\n";
  //   }
  // }

  return EXIT_SUCCESS;
}