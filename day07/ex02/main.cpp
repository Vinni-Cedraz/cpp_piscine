#include <cstdlib>
#include <iostream>
#include <sstream>
#include "Array.hpp"

#define MAX_VAL 15
int main(int, char**) {
  Array<int> my_array_class(MAX_VAL);
  int* mirror = new int[MAX_VAL];
  srand(time(NULL));
  // TESTING [] OPERATOR:
  for (int i = 0; i < MAX_VAL; i++) {
    const int value = rand();
    my_array_class[i] = value;
    mirror[i] = value;
  }
  for (int i = 0; i < MAX_VAL; i++) {
    if (mirror[i] != my_array_class[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
      return 1;
    }
  }

  // TESTING COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR:
  {
    Array<int> tmp = my_array_class;
    Array<int> test(tmp);
  }

  try {
    my_array_class[-2] = 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  try {
    my_array_class[MAX_VAL] = 0;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  Array<std::string> my_array_class_strings(MAX_VAL);
  for (int i = 0; i < MAX_VAL; i++) {
    std::stringstream index;
    index << i + 1;
    my_array_class_strings[i] = "banana_" + index.str();
  }
  for (int i = 0; i < MAX_VAL; i++) {
    std::cout << my_array_class_strings[i] << std::endl;
  }
  delete[] mirror;  //
}
