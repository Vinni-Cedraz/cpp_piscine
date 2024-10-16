#pragma once

#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

#define VECTOR 0
#define LIST 1
#define CYAN "\033[36m"
#define ORANGE "\033[33m"
#define RESET "\033[0m"


typedef std::list<std::pair<int, int> > paired_list;
typedef std::vector<std::pair<int, int> > paired_vector;

class PmergeMe {
private:
  // LISTS:
  paired_list pairs;
  paired_list sorted_pairs;
  std::list<int> sorted;
  std::list<int> pending;
  std::list<int> jacobsthal_lst;
  std::list<int> index_list;
  // VECTORS:
  paired_vector vec_pairs;
  paired_vector vec_sorted_pairs;
  std::vector<int> vec_sorted;
  std::vector<int> vec_pending;
  std::vector<int> vec_jacobsthal;
  std::vector<int> index_vector;
  // ODD
  int odd_one_out;

public:
  PmergeMe(int argc, char **argv, bool vec_or_lst);
  // LISTS:
  std::list<int> input_list;
  std::list<int> &create_input_list(int argc, char **argv);
  int lst_get_next_jacobsthal();
  paired_list &create_pairs_list();
  std::list<int> &create_index_list();
  paired_list &sort_pairs_list();
  int &separate_pair_lists();
  std::list<int> &generate_jacobsthal_list();
  std::list<int> &insert_pending_into_sorted_list();
  int &take_odd_one_out_lst();
  // VECTORS:
  std::vector<int> input_vector;
  std::vector<int> &create_input_vector(int argc, char **argv);
  int vec_get_next_jacobsthal();
  paired_vector &create_pairs_vector();
  std::vector<int> &create_index_vector();
  paired_vector &sort_pairs_vector();
  int &separate_pair_vectors();
  std::vector<int> &generate_jacobsthal_vector();
  std::vector<int> &insert_pending_into_sorted_vector();
  int &take_odd_one_out_vec();
};

std::ostream &operator<<(std::ostream &os, const std::list<int> &lst);
std::ostream &operator<<(std::ostream &os, const paired_list &lst);
std::ostream &operator<<(std::ostream &os, const std::vector<int> &lst);
std::ostream &operator<<(std::ostream &os, const paired_vector &lst);
