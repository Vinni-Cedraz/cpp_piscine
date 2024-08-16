#include "RPN.hpp"
#include <iostream>
#include <sstream>

RPN::RPN(void) { std::cout << "RPN class default constructor called." << std::endl; };

RPN::RPN(const RPN &RPN) {
  std::cout << "RPN class copy constructor called." << std::endl;
  *this = RPN;
};

RPN &RPN::operator=(const RPN &rhs) {
  std::cout << "RPN class copy assign operator called." << std::endl;
  if (this != &rhs) {
    *this = rhs;
  }
  return *this;
};

RPN::~RPN(void) { std::cout << "RPN class destructor called." << std::endl; };

void RPN::calc(char *expression) {
  try {
    this->_parseExpression(expression);
    println(GREEN << this->_RPNStack.top());
  } catch (std::exception &e) {
    errorln(e.what());
    return;
  }
};

void RPN::_doTheMath(char mOperator) {
  int nbr1 = this->_RPNStack.top();
  this->_RPNStack.pop();
  int nbr2 = this->_RPNStack.top();
  this->_RPNStack.pop();
  switch (mOperator) {
  case '+':
    this->_RPNStack.push(nbr2 + nbr1);
    break;
  case '-':
    this->_RPNStack.push(nbr2 - nbr1);
    break;
  case '*':
    this->_RPNStack.push(nbr2 * nbr1);
    break;
  case '/':
    this->_RPNStack.push(nbr2 / nbr1);
    break;

  default:
    throw std::invalid_argument("Error: Operator not valid.");
  }
}

void RPN::_parseExpression(std::string expression) {
  std::string buffer;
  std::stringstream stream(expression);
  std::string generic;

  while (stream >> buffer) {
    generic += buffer;
    if (isdigit(*buffer.begin())) {
      this->_RPNStack.push(*buffer.begin() - '0');
    } else {
      if (this->_RPNStack.size() <= 1) {
        throw std::range_error("Error: Less than two operands inside the stack.");
      } else
        this->_doTheMath(*buffer.begin());
    }
  }
}
