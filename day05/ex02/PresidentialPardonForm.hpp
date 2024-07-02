#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
  private:
    std::string target;

  public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &obj);
    ~PresidentialPardonForm();
    PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);

    void execute(Bureaucrat const &executor) const;
};
