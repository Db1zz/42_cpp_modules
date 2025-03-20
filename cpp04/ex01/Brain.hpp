#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

#define IDEAS_SIZE 1024

class Brain {
public:
  Brain();
  Brain(const Brain& to_copy);
  ~Brain();
  Brain& operator=(const Brain& to_copy);

protected:
  void copyIdeas(const Brain& to_copy);

  std::string _ideas[IDEAS_SIZE];
};

#endif  // BRAIN_HPP