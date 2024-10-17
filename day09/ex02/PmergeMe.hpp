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
  int odd_one_out;

public:
  PmergeMe(int argc, char **argv);
  paired_list &create_pairs();
  paired_list &get_pairs();
  paired_list &sort_pairs();
  void separate_pairs();
  std::list<int> &get_sorted();
  std::list<int> &get_pending();
};

std::ostream &operator<<(std::ostream &os, const std::list<int> &lst);
std::ostream &operator<<(std::ostream &os, const paired_list &lst);
