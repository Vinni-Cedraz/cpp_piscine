#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : name("default"), grade_to_execute(150), grade_to_sign(150), is_signed(false) {}

AForm::AForm(const AForm &copy)
    : name(copy.name), grade_to_execute(copy.grade_to_execute), grade_to_sign(copy.grade_to_sign),
      is_signed(copy.is_signed) {}

AForm &AForm::operator=(const AForm &rhs) {
    if (this == &rhs)
        return *this;
    is_signed = rhs.is_signed;
    return *this;
}

AForm::AForm(std::string name, int grade_to_execute, int grade_to_sign)
    : name(name), grade_to_execute(grade_to_execute), grade_to_sign(grade_to_sign), is_signed(false) {
    if (grade_to_execute < 1 || grade_to_sign < 1)
        throw AForm::GradeTooHighException();
    else if (grade_to_execute > 150 || grade_to_sign > 150)
        throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

const char *AForm::GradeTooLowException::what() const throw (){
	return "Grade too low!";
}

const char *AForm::GradeTooHighException::what() const throw (){
	return "Grade too high!";
}

std::string AForm::getName() const { return this->name; }

int AForm::getGradeToExecute() const { return this->grade_to_execute; }

int AForm::getGradeToSign() const { return this->grade_to_sign; }

bool AForm::getIsSigned() const { return this->is_signed; }

void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > this->grade_to_sign)
        throw AForm::GradeTooLowException();
    else if (this->is_signed)
        throw std::runtime_error("AForm already signed!");
    else
        this->is_signed = true;
}

std::ostream &operator<<(std::ostream &out, AForm const &form) {
	out << "AForm: " << form.getName() << std::endl
		<< "Grade to sign: " << form.getGradeToSign() << std::endl
		<< "Grade to execute: " << form.getGradeToExecute() << std::endl
		<< "Is signed: " << form.getIsSigned() << std::endl;
	return out;
}

void AForm::checkGrade(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
}
