#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc == 1) {
    errorln("Error: Not enough arguments.");
    println(CYAN << "Usage: ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"");
  } else if (argc > 2) {
    errorln("Error: Too many arguments.");
    println(CYAN << "Usage: ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"");
  }
  RPN rpn;
  rpn.calc(argv[1]);
}
