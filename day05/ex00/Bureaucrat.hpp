#pragma once

#include <string>

#pragma once

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[93m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

class Bureaucrat {
private:
  const std::string name;
  int grade;

public:
  // orthodox cannonical stuff:
  Bureaucrat();
  Bureaucrat(std::string name, int grade);
  Bureaucrat(const Bureaucrat &copy);
  Bureaucrat &operator=(const Bureaucrat &assign);
  ~Bureaucrat();

  // getters:
  std::string getName() const;
  int getGrade() const;

  // increment and decrement grade:
  void incrementGrade();
  void decrementGrade();
  // exceptions:
  struct GradeTooHighException : public std::exception {
    virtual const char *what() const throw();
  };
  struct GradeTooLowException : public std::exception {
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &lhs, const Bureaucrat &rhs);
