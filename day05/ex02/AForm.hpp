#pragma once

#include <iostream>
class Bureaucrat;

class AForm {
  private:
    const std::string name;
    const int grade_to_execute;
    const int grade_to_sign;
    bool is_signed;

  public:
    AForm();
    virtual ~AForm();
    AForm(const AForm &copy);
    AForm &operator=(const AForm &rhs);
    AForm(std::string name, int grade_to_execute, int grade_to_sign);
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
	virtual void execute(Bureaucrat const &executor) const = 0;
	void checkGrade(const Bureaucrat &executor) const;
};

std::ostream &operator<<(std::ostream &out, const AForm &rhs);
