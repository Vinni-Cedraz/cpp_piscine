#pragma once

#include <iterator>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
 public:
  MutantStack() {}
  ~MutantStack() {}
  MutantStack(const MutantStack &obj) {
    if (this != &obj) *this = obj;
  }
  MutantStack &operator=(const MutantStack &other) {
    if (this != &other) std::stack<T>::operator=(other);
    return (*this);
  }

  typedef typename std::stack<T>::container_type::iterator iterator;
  iterator begin(void) { return (this->c.begin()); }
  iterator end(void) { return (this->c.end()); }
};
