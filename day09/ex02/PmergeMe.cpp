#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv) {
  if (argc < 2)
    std::cerr << "wrong input" << std::endl;
  for (int i = 1; i < argc; i++)
    input_list.push_back(atoi(argv[i]));
  if (input_list.size() % 2 != 0) {
    int back = input_list.back();
    input_list.pop_back();
    odd_one_out = back;
  }
  pairs = create_pairs();
  std::cout << "odd one out: " << odd_one_out << std::endl;
}

paired_list &PmergeMe::create_pairs() {
  std::list<int>::iterator it = input_list.begin();
  while (it != input_list.end()) {
    pairs.push_back(std::make_pair(*it, *(++it)));
    it++;
  }
  return pairs;
}

void PmergeMe::separate_pairs() {
  for (paired_list::iterator it = pairs.begin(); it != pairs.end(); it++) {
    sorted.push_back(it->first);
    pending.push_back(it->second);
  }
  pending.push_back(odd_one_out);
}

paired_list &PmergeMe::sort_pairs() {
  std::cout << "Sorted Pairs: " << std::endl;
  for (paired_list::iterator it = pairs.begin(); it != pairs.end(); it++)
    if (it->first > it->second)
      std::swap(it->first, it->second);
  pairs.sort();
  return pairs;
}

paired_list &PmergeMe::get_pairs() {
  std::cout << "Pairs: " << std::endl;
  return pairs;
}

std::list<int> &PmergeMe::get_sorted() {
  std::cout << "Sorted: ";
  return sorted;
}
std::list<int> &PmergeMe::get_pending() {
  std::cout << "Pending: ";
  return pending;
}
std::ostream &operator<<(std::ostream &os, const std::list<int> &lst) {
  for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); it++) {
    os << *it << " ";
  }
  return os;
}

std::ostream &operator<<(std::ostream &os, const paired_list &lst) {
  for (paired_list::const_iterator it = lst.begin(); it != lst.end(); it++) {
    os << "(" << it->first << ", " << it->second << ")" << std::endl;
  }
  return os;
}
