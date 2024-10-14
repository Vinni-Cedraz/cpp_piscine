#include <iostream>

#include "RPN.hpp"

void too_few_args() {
  std::cerr << RED << "Error: Not enough arguments." << RESET << std::endl;
  std::cout << "Usage: ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << RESET << std::endl;
}

void too_many_args() {
  std::cerr << RED << "Error: Too many arguments." << RESET << std::endl;
  std::cout << CYAN << "Usage: ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << RESET << std::endl;
}

int main(int argc, char **argv) {
  RPN rpn;
  if (argc == 2)
    return rpn.run(argv[1]);
  else if (argc < 2)
    too_few_args();
  else
    too_many_args();
}
