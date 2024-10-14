#pragma once
#include <cstdlib>
#include <stack>
#include <string>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\033[1;36m"
#define ORANGE "\033[0;38;5;166m"
#define RESET "\033[0m"

class RPN {
 public:
  RPN(void);
  ~RPN(void);
  RPN(const RPN &RPN);
  RPN &operator=(const RPN &rhs);

  int run(char *expression);

 private:
  void parse(std::string expression);
  void calculate(char mOperator);

  std::stack<int> memory;
};
