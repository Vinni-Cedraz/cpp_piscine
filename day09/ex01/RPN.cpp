#include <cstdlib>
#include <iostream>
#include <sstream>

#include "RPN.hpp"

// ORTHODOX CANNONICAL FORM:
RPN::RPN(void) {};
RPN::RPN(const RPN &RPN) { *this = RPN; };
RPN &RPN::operator=(const RPN &rhs) { if (this != &rhs) { this->memory = rhs.memory; } return *this; };

RPN::~RPN(void) {};
// ORTHODOX CANNONICAL FORM END

// MAIN LOGIC:
int RPN::run(char *expression) {
  try {
    parse(expression);
    std::cout << GREEN << memory.top() << RESET << std::endl;
    return 0;
  } catch (std::exception &e) {
    std::cerr << RED << e.what() << RESET << std::endl;
    return 1;
  }
};

void RPN::calculate(char op) {
  const int nbr1 = memory.top();
  memory.pop();
  const int nbr2 = memory.top();
  memory.pop();
  switch (op) {
    case '+':
      memory.push(nbr2 + nbr1);
      break;
    case '-':
      memory.push(nbr2 - nbr1);
      break;
    case '*':
      memory.push(nbr2 * nbr1);
      break;
    case '/':
      memory.push(nbr2 / nbr1);
      break;
    default:
      throw std::invalid_argument("Error: Operator not valid.");
  }
}

void RPN::parse(std::string expression) {
  std::string buffer;
  std::stringstream stream(expression);

  while (stream >> buffer) {
    if (isdigit(buffer[0]))
      memory.push(buffer[0] - '0');
    else if (memory.size() <= 1)
      throw std::range_error("Error: Less than two operands inside the stack.");
    else
      calculate(buffer[0]);
  }
}
