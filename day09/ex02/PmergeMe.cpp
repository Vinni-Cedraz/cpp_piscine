#include "PmergeMe.hpp"

const int sixteen_jacobs[] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845};

#include <ctime>

PmergeMe::PmergeMe(int argc, char **argv, bool vector_or_list) : odd_one_out(-42) {
  if (vector_or_list == LIST) {
    clock_t start = clock();

    if (argc < 2)
      std::cerr << "wrong input" << std::endl;
    for (int i = 1; i < argc; i++)
      input_list.push_back(atoi(argv[i]));
    if (input_list.size() % 2 != 0) {
      int back = input_list.back();
      input_list.pop_back();
      odd_one_out = back;
    }

    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;

    std::cout << "Time taken for data management of list input: " << elapsed << " s" << std::endl;
  }
}

paired_list &PmergeMe::create_pairs() {
  std::list<int>::iterator it = input_list.begin();
  while (it != input_list.end()) {
    pairs.push_back(std::make_pair(*it, *(++it)));
    it++;
  }
  return pairs;
}

paired_list &PmergeMe::sort_pairs() {
  for (paired_list::iterator it = pairs.begin(); it != pairs.end(); it++)
    if (it->first > it->second)
      std::swap(it->first, it->second);
  pairs.sort();
  return pairs;
}

int &PmergeMe::separate_pairs() {
  for (paired_list::iterator it = pairs.begin(); it != pairs.end(); it++) {
    sorted.push_back(it->first);
    pending.push_back(it->second);
  }
  if (-42 != odd_one_out)
    pending.push_back(odd_one_out);
  return odd_one_out;
}

std::list<int> &PmergeMe::generate_jacobsthal_seq() {
  for (int i = 0; i <= 15; i++) {
    if (sixteen_jacobs[i] >= (const int)pending.size())
      break;
    jacobsthal.push_back(sixteen_jacobs[i]);
  }
  return jacobsthal;
}

int PmergeMe::get_next_jacobsthal() {
  int front = jacobsthal.front();
  jacobsthal.pop_front();
  return front;
}

int already_there(int jacob, std::list<int> index_list) {
  std::list<int>::iterator begin = index_list.begin();
  std::list<int>::iterator end = index_list.end();

  for (std::list<int>::iterator it = begin; it != end; it++)
    if (*it == jacob)
      return true;
  return false;
}

std::list<int> &PmergeMe::create_index_list() {
  while (index_list.size() < pending.size() && !jacobsthal.empty()) {
    int last = index_list.back();
    int jacob = get_next_jacobsthal();

    index_list.push_back(jacob--);
    while (jacob > last && index_list.size() < pending.size()) {
      if (!already_there(jacob, index_list))
        index_list.push_back(jacob);
      jacob--;
    }
  }
  if (index_list.size() < pending.size()) {
    int missing = pending.size() - 1;
    while (index_list.size() < pending.size())
      index_list.push_back(missing--);
  }
  return index_list;
}

static std::list<int>::iterator list_binary_search(std::list<int> &sorted, int value) {
  std::list<int>::iterator left = sorted.begin();
  std::list<int>::iterator right = sorted.end();
  while (std::distance(left, right) > 0) {
    std::list<int>::iterator mid = left;
    std::advance(mid, std::distance(left, right) / 2);
    if (*mid < value)
      left = ++mid;
    else
      right = mid;
  }
  return left;
}

std::list<int> &PmergeMe::insert_sorted() {
  for (std::list<int>::iterator it = index_list.begin(); it != index_list.end(); it++) {
    std::list<int>::iterator pending_it = pending.begin();
    std::advance(pending_it, *it);
    int value = *pending_it;
    std::list<int>::iterator position = list_binary_search(sorted, value);
    sorted.insert(position, value);
  }

  return sorted;
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
