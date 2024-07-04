#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &assign) {
    if (this == &assign)
        return *this;
    grade = assign.grade;
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade) {}

std::string Bureaucrat::getName() const { return name; }
int Bureaucrat::getGrade() const { return grade; }

void Bureaucrat::incrementGrade() {
    if (grade == 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (grade == 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs) {
    std::cout << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
    return out;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() { return "Bureaucrat grade is too low"; }

const char *Bureaucrat::GradeTooHighException::what() const throw() { return "Bureaucrat grade is too high"; }

void Bureaucrat::signForm(Form &form) const {
    try {
        form.beSigned(*this);
        std::cout << GRN "Bureaucrat " << name << " signed Form \"" << form.getName() << "\"" RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << RED "Bureaucrat " << name << " couldn’t sign \"" << form.getName() << "\" because " << e.what()
                  << RESET << std::endl;
    }
}

void Bureaucrat::executeForm(const Form &form) const {
    try {
        form.execute(*this);
        std::cout << GRN "Bureaucrat " << name << " executed \"" << form.getName() << "\"" RESET << std::endl;
    } catch (std::exception &e) {
        std::cout << RED "Bureaucrat " << name << " couldn’t execute \"" << form.getName() << "\" because " << e.what()
                  << RESET << std::endl;
    }
}
