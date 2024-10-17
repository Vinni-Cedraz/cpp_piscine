#include "PmergeMe.hpp"

int main(int argc, char **argv) {
  if (argc < 2) {
	std::cerr << "wrong input" << std::endl;
  }
  PmergeMe merge_insertion_sorter(argc, argv);
  std::cout << merge_insertion_sorter.get_pairs();
  std::cout << merge_insertion_sorter.sort_pairs();
  std::cout << merge_insertion_sorter.separate_pairs() << std::endl;
  std::cout << merge_insertion_sorter.get_sorted() << std::endl;
  std::cout << merge_insertion_sorter.get_pending() << std::endl;
}
