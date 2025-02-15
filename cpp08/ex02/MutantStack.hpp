#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <cstddef> // #include <stddef.h>

/*
  Before implementing anything read this dolbayob na goshe:

  https://en.cppreference.com/w/cpp/container/stack#:~:text=The%20standard%20containers%20std%3A%3A,std%3A%3Adeque%20is%20used.
  https://en.cppreference.com/w/cpp/container/deque

  Vivody sdelany:
  Stack based on std::deque contianer which has iterators, so we simply can use them.
*/

template <typename T>
class MutantStack : public std::stack<T> {
public:
  typedef typename std::stack<T>::container_type::iterator rev_iterator;
  typedef typename std::stack<T>::container_type::reverse_iterator iterator;
  typedef typename std::stack<T>::container_type::const_iterator const_rev_iterator;
  typedef typename std::stack<T>::container_type::const_reverse_iterator const_iterator;

  /*
    end - 0,1,2,3,4 - begin
    ++ == --
  */

  iterator begin() {
    return std::reverse_iterator<rev_iterator>(this->c.end());
  }

  iterator end() {
    return std::reverse_iterator<rev_iterator>(this->c.begin());
  }

  const_iterator begin() const {
    return std::reverse_iterator<const_rev_iterator>(this->c.end());
  }

  const_iterator end() const {
    return std::reverse_iterator<const_rev_iterator>(this->c.begin());
  }
};

#endif  // MUTANTSTACK_HPP
