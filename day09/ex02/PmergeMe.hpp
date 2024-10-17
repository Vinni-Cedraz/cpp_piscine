#pragma once

#include <cstdlib>
#include <iostream>
#include <list>

typedef std::list<std::pair<int, int> > paired_list;

class PmergeMe {
private:
  std::list<int> input_list;
  paired_list pairs;
  paired_list sorted_pairs;
  std::list<int> sorted;
  std::list<int> pending;
  std::list<int> jacobsthal;
  std::list<int> insertion;
  std::list<int> index_list;
  int odd_one_out;

public:
  PmergeMe(int argc, char **argv);
  int get_jacobsthal();
  paired_list &create_pairs();
  std::list<int> &create_index_list();
  paired_list &get_pairs();
  paired_list &sort_pairs();
  //returns the odd_one_out:
  int &separate_pairs();
  std::list<int> &get_sorted();
  std::list<int> &get_pending();
};

std::ostream &operator<<(std::ostream &os, const std::list<int> &lst);
std::ostream &operator<<(std::ostream &os, const paired_list &lst);
