#include <iostream>
#include <vector>
#include <algorithm>

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

std::vector<int> merge_insertion_sort(std::vector<int> numbers) {
  bool is_array_odd = numbers.size() % 2 == 0;
  size_t array_size = numbers.size() - is_array_odd;
  size_t index = 0;
  std::vector<int> a;
  std::vector<int> b;
  std::vector<int> c;

  while (index < array_size) {
    a.push_back(std::max(numbers[index], numbers[index + 1]));
    b.push_back(std::min(numbers[index], numbers[index + 1]));
    index += 2;
  }
  std::cout << "a: "; display_array(a);
  std::cout << "b: "; display_array(b);
  return a;
}

/*
  Step one is done, we have splitted array on pairs.
*/
int main() {
  std::vector<int> input;
  std::cout << "asdas" << c;
  merge_insertion_sort({11, 3, 65, 1, 2, 8, 10, 5, 4, 8});
}