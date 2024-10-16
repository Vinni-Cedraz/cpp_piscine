#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : Form(other), target(other.target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
    if (this == &other)
        return *this;
    Form::operator=(other);
    target = other.target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	checkGrade(executor);
    std::cout << "*drilling noises*\n";
    if (rand() % 2)
        std::cout << target << " has been robotomized successfully\n";
    else
        std::cout << target << " robotomization failed\n";
}
