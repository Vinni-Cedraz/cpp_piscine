#pragma once
#include <cstdlib>
#include <stack>
#include <string>

#define println(x) std::cout << x << RESET << std::endl;
#define errorln(x) std::cerr << RED << x << RESET << std::endl;

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define ORANGE "\033[0;38;5;166m"
#define RESET "\033[0m"

class RPN {

public:
  RPN(void);
  ~RPN(void);
  void calc(char *expression);

private:
  RPN(const RPN &RPN);
  RPN &operator=(const RPN &rhs);
  void _parseExpression(std::string expression);
  void _doTheMath(char mOperator);

  std::stack<int> _RPNStack;
};
