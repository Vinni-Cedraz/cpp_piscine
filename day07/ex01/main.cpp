#include <iostream>

#include "iter.hpp"

int main(void) {
  {
    std::cout << "TEST 1 (INT ARRAY)" << std::endl;
    int array[5] = {1, 2, 3, 4, 5};

    std::cout << "Calling the iter function:" << std::endl;
    ::iter(array, 5, print<int>);
  }
  std::cout << std::endl;
  {
    std::cout << "TEST 2 (FLOAT ARRAY)" << std::endl;
    float array[5] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};

    std::cout << "Calling the iter function:" << std::endl;
    ::iter(array, 5, ::print<float>);
  }
  std::cout << std::endl;
  {
    std::cout << "TEST 3 (DOUBLE ARRAY)" << std::endl;
    double array[5] = {1.1111, 2.2222, 3.3333, 4.4444, 5.5555};

    std::cout << "Calling the iter function:" << std::endl;
    ::iter(array, 5, ::print<double>);
  }
  std::cout << std::endl;
  {
    std::cout << "TEST 4 (STRING ARRAY)" << std::endl;
    std::string array[5] = {"one", "two", "third", "four", "five"};

    std::cout << "Calling the iter function:" << std::endl;
    ::iter(array, 5, ::print<std::string>);
  }
}
