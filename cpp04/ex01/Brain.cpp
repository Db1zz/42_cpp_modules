#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
  std::cout << "Brain's Default Constructor was called\n";
}

Brain::Brain(const Brain& to_copy) {
  std::cout << "Brain's Copy Constructor was called\n";
  copyIdeas(to_copy);
}

Brain::~Brain() {
  std::cout << "Brain's Default Destructor was called\n";
}

Brain& Brain::operator=(const Brain& to_copy) {
  if (this == &to_copy) {
    return *this;
  }
  copyIdeas(to_copy);
  return *this;
}

void Brain::copyIdeas(const Brain& to_copy) {
  for (int i = 0; i < IDEAS_SIZE; i++) {
    _ideas[i] = to_copy._ideas[i];
  }
}