#include <iostream>
#include <vector>

#include "easyfind.hpp"

int main() {
  std::vector<int> map;

  for (int i = 0; i < 10; i++) {
    map.push_back(i);
  }
  map.push_back(42);
  for (int i = 21; i < 31; i++) {
    map.push_back(i);
  }
  std::cout << CYAN "This is the vector of ints" RESET << std::endl;
  std::cout << map << std::endl;
  std::vector<int>::iterator i;
  std::cout << CYAN "Looking for 42: " RESET << std::endl;
  i = easyfind(map, 42);
  std::cout << CYAN "\n\nLooking for 43: " RESET << std::endl;
  i = easyfind(map, 43);
  (void)i;
}
