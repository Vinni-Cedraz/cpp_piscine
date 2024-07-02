#pragma once

#include <iostream>
class Bureaucrat;

class Form {
  private:
    const std::string name;
    const int grade_to_execute;
    const int grade_to_sign;
    bool is_signed;

  public:
    Form();
    ~Form();
    Form(const Form &copy);
    Form &operator=(const Form &rhs);
    Form(std::string name, int grade_to_execute, int grade_to_sign);
    std::string getName() const;
    int getGradeToExecute() const;
    int getGradeToSign() const;
    bool getIsSigned() const;
    void beSigned(const Bureaucrat &b);
    class GradeTooHighException : public std::exception {
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Form &rhs);
