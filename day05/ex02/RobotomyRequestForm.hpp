#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
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
