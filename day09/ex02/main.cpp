#include "PmergeMe.hpp"
#include <cassert>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "wrong input" << std::endl;
  }
  // VERSION DONE WITH LISTS ONLY:
  {
    PmergeMe merge_insertion_sorter(argc, argv, LIST);
    clock_t start = clock();
    merge_insertion_sorter.create_pairs();
    merge_insertion_sorter.sort_pairs();
    merge_insertion_sorter.separate_pairs();
    merge_insertion_sorter.generate_jacobsthal_seq();
    merge_insertion_sorter.create_index_list();
    std::list<int> sorted_by_me = merge_insertion_sorter.insert_sorted();
    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    std::cout << sorted_by_me << std::endl;
    std::cout << "Time taken for sorting when using lists: " << elapsed << " s" << std::endl;
	// Check if the list is sorted:
    merge_insertion_sorter.input_list.sort();
    assert(sorted_by_me == merge_insertion_sorter.input_list);
  }
}
