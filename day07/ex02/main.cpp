#include "Array.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>
#define CYAN "\033[36m"
#define RESET "\033[0m"

#define MAX_VAL 5
int main(int, char **) {

  std::cout << CYAN "Proving that it works just like an array of ints:\n" RESET;
  Array<int> my_array_class(MAX_VAL);
  int *default_array = new int[MAX_VAL];
  srand(time(NULL));
  // TESTING [] OPERATOR:
  for (int i = 0; i < MAX_VAL; i++) {
    const int value = rand() % 50;
    my_array_class[i] = value;
    default_array[i] = value;
  }
  for (int i = 0; i < MAX_VAL; i++) {
    std::cout << "my_array_class[" << i << "] = " << my_array_class[i] << std::endl;
    std::cout << "default_array[" << i << "] = " << default_array[i] << std::endl;
  }
  delete[] default_array;

  // TESTING COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR:
  {
    Array<int> tmp = my_array_class;
    Array<int> test(tmp);
  }

  std::cout << CYAN "trying to access indexes out of range should print exceptions:\n" RESET;
  try {
    my_array_class[-2] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  try {
    my_array_class[MAX_VAL] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  std::cout << CYAN "Proving that the Array template class also works for strings:" RESET << std::endl;
  Array<std::string> my_array_class_strings(MAX_VAL);
  for (int i = 0; i < MAX_VAL; i++) {
    std::stringstream index;
    index << i + 1;
    my_array_class_strings[i] = "banana_" + index.str();
  }
  for (int i = 0; i < MAX_VAL; i++) {
    std::cout << my_array_class_strings[i] << std::endl;
  }

  std::cout << CYAN "Overwritting an Array a(5) with an Array b(10) of different size:\n" RESET;
  Array<int> a(5);
  for (int i = 0; i != 5; i++) {
    a[i] = i;
  }

  Array<int> b(10);
  for (int i = 0; i != 10; i++) {
    b[i] = i;
  }

  a = b;
  std::cout << "Array a size should now be 10: " << a.size() << std::endl;
}
