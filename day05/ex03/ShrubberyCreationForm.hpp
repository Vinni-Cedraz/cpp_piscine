#pragma once
// create the ShrubberyCreationForm class here
#include "Form.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form {
  private:
    std::string target;

  public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const &other);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
    virtual ~ShrubberyCreationForm();
    void execute(Bureaucrat const &executor) const;
};
