#pragma once

#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

#define VECTOR 0
#define LIST 1

typedef std::list<std::pair<int, int> > paired_list;
typedef std::vector<std::pair<int, int> > paired_vector;

class PmergeMe {
private:
  // LISTS:
  paired_list pairs;
  paired_list sorted_pairs;
  std::list<int> sorted;
  std::list<int> pending;
  std::list<int> jacobsthal;
  std::list<int> index_list;
  // // VECTORS:
  // paired_vector vec_pairs;
  // paired_vector vec_sorted_pairs;
  // std::vector<int> vec_sorted;
  // std::vector<int> vec_pending;
  // std::vector<int> vec_jacobsthal;
  // std::vector<int> vec_index_list;
  int odd_one_out;

public:
  std::list<int> input_list;
  PmergeMe(int argc, char **argv, bool vec_or_lst);
  int get_next_jacobsthal();
  paired_list &create_pairs();
  std::list<int> &create_index_list();
  paired_list &sort_pairs();
  // returns the odd_one_out:
  int &separate_pairs();
  std::list<int> &generate_jacobsthal_seq();
  std::list<int> &insert_sorted();
};

std::ostream &operator<<(std::ostream &os, const std::list<int> &lst);
std::ostream &operator<<(std::ostream &os, const paired_list &lst);
