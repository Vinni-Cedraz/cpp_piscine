#include <algorithm>
#include <cassert>

#include "PmergeMe.hpp"

std::list<int> run_merge_insertion_sort_with_lists(PmergeMe &sorter) {
  sorter.create_pairs_list();
  sorter.sort_pairs_list();
  sorter.separate_pair_lists();
  sorter.generate_jacobsthal_list();
  sorter.create_index_list();
  return sorter.insert_pending_into_sorted_list();
}

std::vector<int> run_merge_insertion_sort_with_vectors(PmergeMe &sorter) {
  sorter.create_pairs_vector();
  sorter.sort_pairs_vector();
  sorter.separate_pair_vectors();
  sorter.generate_jacobsthal_vector();
  sorter.create_index_vector();
  return sorter.insert_pending_into_sorted_vector();
}

int main(int argc, char **argv) {
  try {
    // DONE WITH LISTS ONLY:
    PmergeMe lst_sorter(argc, argv, LIST);
    clock_t start = clock();
    std::list<int> sorted_by_me = run_merge_insertion_sort_with_lists(lst_sorter);
    clock_t end = clock();
    double elapsed = double(end - start) * 1000000 / CLOCKS_PER_SEC;

    // DONE WITH VECTORS ONLY:
    PmergeMe vec_sorter(argc, argv, VECTOR);
    clock_t start_vec = clock();
    std::vector<int> sorted_by_me_vec = run_merge_insertion_sort_with_vectors(vec_sorter);
    clock_t end_vec = clock();
    double elapsed_vec = double(end_vec - start_vec) * 1000000 / CLOCKS_PER_SEC;

    // PRINTING:
    std::cout << "============================== RAW INPUT ==============================" << std::endl;
    std::cout << vec_sorter.input_vector << std::endl;
    std::cout << "============================== SORTED =================================" << std::endl;
    std::cout << sorted_by_me_vec << std::endl;
    std::cout << "=======================================================================" << std::endl;
    std::cout << ORANGE "Time taken for sorting with lists: " RESET << elapsed << " microseconds" << std::endl;
    std::cout << CYAN "Time taken for sorting with vectors: " RESET << elapsed_vec << " microseconds" << std::endl;

    // ASSERTIONS:
    lst_sorter.input_list.sort();
    assert(sorted_by_me == lst_sorter.input_list);
    std::sort(vec_sorter.input_vector.begin(), vec_sorter.input_vector.end());
    assert(sorted_by_me_vec == vec_sorter.input_vector);
  } // EXCEPTIONS:
  catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
