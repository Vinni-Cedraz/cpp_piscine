#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// PresidentialPardonForm: Required grades: sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox.PresidentialPardonForm: Required grades: sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox.

// Constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) {
    this->target = target;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) {
    this->target = other.target;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// Assignment operator
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this == &other)
        return *this;
    AForm::operator=(other);
    this->target = other.target;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	checkGrade(executor);
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
