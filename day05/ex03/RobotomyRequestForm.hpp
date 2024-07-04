#pragma once

#include "Form.hpp"

class RobotomyRequestForm : public Form {
  private:
    std::string target;

  public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm const &other);
    RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
    virtual ~RobotomyRequestForm();
    void execute(Bureaucrat const &executor) const;
};
