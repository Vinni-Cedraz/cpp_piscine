#pragma once
#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <queue>
#define CYAN "\033[0;36m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

template <typename T>
typename T::iterator easyfind(T &container, int b) {
  const typename T::iterator it = std::find(container.begin(), container.end(), b);
  std::cout << "easyfind called\n";
  if (it == container.end()) {
    std::cerr << RED "Element Not Found!" RESET << std::endl;
  } else {
    std::cout << CYAN "Element Found: \n" RESET;
    std::cout << "map[" << std::distance(container.begin(), it) << "] ==> " << *it << std::endl;
  }
  return it;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec) {
  for (typename std::vector<T>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
    os << "["<< std::distance(vec.begin(), i) << "] " << *i << std::endl;
  }
  return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::list<T> &vec) {
  for (typename std::vector<T>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
    os << "["<< std::distance(vec.begin(), i) << "] " << *i << std::endl;
  }
  return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::queue<T> &vec) {
  for (typename std::vector<T>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
    os << "["<< std::distance(vec.begin(), i) << "] " << *i << std::endl;
  }
  return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::deque<T> &vec) {
  for (typename std::vector<T>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
    os << "["<< std::distance(vec.begin(), i) << "] " << *i << std::endl;
  }
  return os;
}
