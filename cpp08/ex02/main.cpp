#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <deque>

void test_mutant_stack(MutantStack<int> container) {
  container.push(5);
  container.push(17);
  std::cout << container.top() << std::endl;
  container.pop();
  std::cout << container.size() << std::endl;
  container.push(3);
  container.push(5);
  container.push(737);

  container.push(0);
  MutantStack<int>::iterator it = container.begin();
  MutantStack<int>::iterator ite = container.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  MutantStack<int> s(container);
}

template <typename DeuqeContainer>
void test_deque_based_containers(DeuqeContainer container) {
  container.push_front(5);
  container.push_front(17);
  std::cout << container.front() << std::endl;
  container.pop_front();
  std::cout << container.size() << std::endl;
  container.push_front(3);
  container.push_front(5);
  container.push_front(737);

  container.push_front(0);
  typename DeuqeContainer::iterator it = container.begin();
  typename DeuqeContainer::iterator ite = container.end();
  ++it;
  --it;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  DeuqeContainer s(container);
}

int main() {
  std::cout << "MutantStack Test\n";
  MutantStack<int> stack;
  test_mutant_stack(stack);
  
  std::cout << "\nstd::list Test\n";
  std::list<int> list;
  test_deque_based_containers(list);

  std::cout << "\nstd::deque Test\n";
  std::deque<int> deque;
  test_deque_based_containers(deque);
  return 0;
}