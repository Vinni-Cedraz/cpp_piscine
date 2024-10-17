#include "PmergeMe.hpp"
#include <algorithm>
#include <cassert>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "wrong input" << std::endl;
  }
  // VERSION DONE WITH LISTS ONLY:
  {
    PmergeMe merge_insertion_sorter(argc, argv, LIST);
    clock_t start = clock();
    merge_insertion_sorter.create_pairs_list();
    merge_insertion_sorter.sort_pairs_list();
    merge_insertion_sorter.separate_pair_lists();
    merge_insertion_sorter.generate_jacobsthal_list();
    merge_insertion_sorter.create_index_list();
    std::list<int> sorted_by_me = merge_insertion_sorter.insert_pending_into_sorted_list();
    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    // std::cout << sorted_by_me << std::endl;
    std::cout << "Time taken for sorting when using lists: " << elapsed << " s" << std::endl;
	// Check if the list is sorted:
    merge_insertion_sorter.input_list.sort();
    assert(sorted_by_me == merge_insertion_sorter.input_list);
  }
  // VERSION DONE WITH VECTORS ONLY:
  {
	PmergeMe merge_insertion_sorter(argc, argv, VECTOR);
	clock_t start = clock();
	merge_insertion_sorter.create_pairs_vector();
	merge_insertion_sorter.sort_pairs_vector();
	merge_insertion_sorter.separate_pair_vectors();
	merge_insertion_sorter.generate_jacobsthal_vector();
	merge_insertion_sorter.create_index_vector();
	std::vector<int> sorted_by_me = merge_insertion_sorter.insert_pending_into_sorted_vector();
	clock_t end = clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC;
	// std::cout << sorted_by_me << std::endl;
	std::cout << "Time taken for sorting when using vectors: " << elapsed << " s" << std::endl;
	// Check if the vector is sorted:
	std::sort(merge_insertion_sorter.input_vector.begin(), merge_insertion_sorter.input_vector.end());
	assert(sorted_by_me == merge_insertion_sorter.input_vector);
  }
}
