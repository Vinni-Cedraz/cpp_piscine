#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <set>

#include "PmergeMe.hpp"

const int sixteen_jacobs[] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845};

PmergeMe::PmergeMe(int argc, char **argv, bool type) : odd_one_out(-42) {
  if (argc < 2) throw std::runtime_error("wrong input");
  if (type == LIST)
    create_input_list(argc, argv);
  else if (type == VECTOR)
    create_input_vector(argc, argv);
}

std::list<int> &PmergeMe::create_input_list(int argc, char **argv) {
  for (int i = 1; i < argc; i++) input_list.push_back(atoi(argv[i]));
  std::set<int> seen;
  for (std::list<int>::iterator it = input_list.begin(); it != input_list.end(); it++) {
    if (seen.find(std::abs(*it)) != seen.end()) throw std::runtime_error("Duplicate element in input list");
    seen.insert(*it);
  }
  take_odd_one_out_lst();
  return input_list;
}

int &PmergeMe::take_odd_one_out_lst() {
  if (input_list.size() % 2 != 0) {
    int back = input_list.back();
    input_list.pop_back();
    odd_one_out = back;
    pending.push_back(odd_one_out);
  }
  return odd_one_out;
}

paired_list &PmergeMe::create_pairs_list() {
  std::list<int>::iterator it = input_list.begin();
  while (it != input_list.end()) {
    pairs.push_back(std::make_pair(*it, *(++it)));
    it++;
  }
  return pairs;
}

paired_list &PmergeMe::sort_pairs_list() {
  for (paired_list::iterator it = pairs.begin(); it != pairs.end(); it++)
    if (it->first > it->second) std::swap(it->first, it->second);
  pairs.sort();
  return pairs;
}

int &PmergeMe::separate_pair_lists() {
  for (paired_list::iterator it = pairs.begin(); it != pairs.end(); it++) {
    sorted.push_back(it->first);
    pending.push_back(it->second);
  }
  return odd_one_out;
}

std::list<int> &PmergeMe::generate_jacobsthal_list() {
  for (int i = 0; i <= 15; i++) {
    if (sixteen_jacobs[i] >= (const int)pending.size()) break;
    jacobsthal_lst.push_back(sixteen_jacobs[i]);
  }
  return jacobsthal_lst;
}

int PmergeMe::lst_get_next_jacobsthal() {
  int front = jacobsthal_lst.front();
  jacobsthal_lst.pop_front();
  return front;
}

int already_there(int jacob, std::list<int> index_list) {
  std::list<int>::iterator begin = index_list.begin();
  std::list<int>::iterator end = index_list.end();
  for (std::list<int>::iterator it = begin; it != end; it++)
    if (*it == jacob) return true;
  return false;
}

std::list<int> &PmergeMe::create_index_list() {
  while (index_list.size() < pending.size() && !jacobsthal_lst.empty()) {
    int last = index_list.back();
    int jacob = lst_get_next_jacobsthal();
    index_list.push_back(jacob--);
    while (jacob > last && index_list.size() < pending.size()) {
      if (!already_there(jacob, index_list)) index_list.push_back(jacob);
      jacob--;
    }
  }
  if (index_list.size() < pending.size()) {
    int missing = pending.size() - 1;
    while (index_list.size() < pending.size()) index_list.push_back(missing--);
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

std::list<int> &PmergeMe::insert_pending_into_sorted_list() {
  for (std::list<int>::iterator it = index_list.begin(); it != index_list.end(); it++) {
    std::list<int>::iterator pending_it = pending.begin();
    std::advance(pending_it, *it);
    int value = *pending_it;
    std::list<int>::iterator position = list_binary_search(sorted, value);
    sorted.insert(position, value);
  }
  if (-42 != odd_one_out) input_list.push_back(odd_one_out);
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

// VECTORS:

std::vector<int> &PmergeMe::create_input_vector(int argc, char **argv) {
  for (int i = 1; i < argc; i++) input_vector.push_back(atoi(argv[i]));
  std::set<int> seen;
  for (std::vector<int>::iterator it = input_vector.begin(); it != input_vector.end(); it++) {
    if (seen.find(std::abs(*it)) != seen.end()) throw std::runtime_error("Duplicate element in input list");
    seen.insert(*it);
  }
  take_odd_one_out_vec();
  return input_vector;
}

int &PmergeMe::take_odd_one_out_vec() {
  if (input_vector.size() % 2 != 0) {
    int back = input_vector.back();
    input_vector.pop_back();
    odd_one_out = back;
    vec_pending.push_back(odd_one_out);
  }
  return odd_one_out;
}

paired_vector &PmergeMe::create_pairs_vector() {
  for (std::vector<int>::iterator it = input_vector.begin(); it != input_vector.end(); it += 2) {
    vec_pairs.push_back(std::make_pair(*it, *(it + 1)));
  }
  return vec_pairs;
}

paired_vector &PmergeMe::sort_pairs_vector() {
  for (paired_vector::iterator it = vec_pairs.begin(); it != vec_pairs.end(); ++it)
    if (it->first > it->second) std::swap(it->first, it->second);
  std::sort(vec_pairs.begin(), vec_pairs.end());
  return vec_pairs;
}

int &PmergeMe::separate_pair_vectors() {
  for (paired_vector::iterator it = vec_pairs.begin(); it != vec_pairs.end(); ++it) {
    vec_sorted.push_back(it->first);
    vec_pending.push_back(it->second);
  }
  return odd_one_out;
}

std::vector<int> &PmergeMe::generate_jacobsthal_vector() {
  for (int i = 0; i <= 15; i++) {
    if (sixteen_jacobs[i] >= (const int)vec_pending.size()) break;
    vec_jacobsthal.push_back(sixteen_jacobs[i]);
  }
  return vec_jacobsthal;
}

int PmergeMe::vec_get_next_jacobsthal() {
  int front = vec_jacobsthal.front();
  vec_jacobsthal.erase(vec_jacobsthal.begin());
  return front;
}

std::vector<int> &PmergeMe::create_index_vector() {
  while (index_vector.size() < vec_pending.size() && !vec_jacobsthal.empty()) {
    int last = index_vector.empty() ? 0 : index_vector.back();
    int jacob = vec_get_next_jacobsthal();
    index_vector.push_back(jacob--);
    while (jacob > last && index_vector.size() < vec_pending.size()) {
      if (std::find(index_vector.begin(), index_vector.end(), jacob) == index_vector.end())
        index_vector.push_back(jacob);
      jacob--;
    }
  }
  if (index_vector.size() < vec_pending.size()) {
    int missing = vec_pending.size() - 1;
    while (index_vector.size() < vec_pending.size()) index_vector.push_back(missing--);
  }
  return index_vector;
}

static std::vector<int>::iterator vector_binary_search(std::vector<int> &sorted, int value) {
  std::vector<int>::iterator left = sorted.begin();
  std::vector<int>::iterator right = sorted.end();
  while (left < right) {
    std::vector<int>::iterator mid = left + (right - left) / 2;
    if (*mid < value)
      left = mid + 1;
    else
      right = mid;
  }
  return left;
}

std::vector<int> &PmergeMe::insert_pending_into_sorted_vector() {
  for (std::vector<int>::iterator it = index_vector.begin(); it != index_vector.end(); ++it) {
    int value = vec_pending[*it];
    std::vector<int>::iterator position = vector_binary_search(vec_sorted, value);
    vec_sorted.insert(position, value);
  }
  if (-42 != odd_one_out) input_vector.push_back(odd_one_out);
  return vec_sorted;
}

std::ostream &operator<<(std::ostream &os, const std::vector<int> &vec) {
  for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
    os << *it << " ";
  }
  return os;
}

std::ostream &operator<<(std::ostream &os, const paired_vector &vec) {
  for (paired_vector::const_iterator it = vec.begin(); it != vec.end(); ++it) {
    os << "(" << it->first << ", " << it->second << ")" << std::endl;
  }
  return os;
}
