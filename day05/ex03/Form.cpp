#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : name("default"), grade_to_execute(150), grade_to_sign(150), is_signed(false) {}

Form::Form(const Form &copy)
    : name(copy.name), grade_to_execute(copy.grade_to_execute), grade_to_sign(copy.grade_to_sign),
      is_signed(copy.is_signed) {}

Form &Form::operator=(const Form &rhs) {
    if (this == &rhs)
        return *this;
    is_signed = rhs.is_signed;
    return *this;
}

Form::Form(std::string name, int grade_to_execute, int grade_to_sign)
    : name(name), grade_to_execute(grade_to_execute), grade_to_sign(grade_to_sign), is_signed(false) {
    if (grade_to_execute < 1 || grade_to_sign < 1)
        throw Form::GradeTooHighException();
    else if (grade_to_execute > 150 || grade_to_sign > 150)
        throw Form::GradeTooLowException();
}

Form::~Form() {}

const char *Form::GradeTooLowException::what() const throw (){
	return "Grade too low!";
}

const char *Form::GradeTooHighException::what() const throw (){
	return "Grade too high!";
}

std::string Form::getName() const { return this->name; }

int Form::getGradeToExecute() const { return this->grade_to_execute; }

int Form::getGradeToSign() const { return this->grade_to_sign; }

bool Form::getIsSigned() const { return this->is_signed; }

void Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > this->grade_to_sign)
        throw Form::GradeTooLowException();
    else if (this->is_signed)
        throw std::runtime_error("Form already signed!");
    else
        this->is_signed = true;
}

std::ostream &operator<<(std::ostream &out, Form const &form) {
	out << "Form: " << form.getName() << std::endl
		<< "Grade to sign: " << form.getGradeToSign() << std::endl
		<< "Grade to execute: " << form.getGradeToExecute() << std::endl
		<< "Is signed: " << form.getIsSigned() << std::endl;
	return out;
}

void Form::checkGrade(const Bureaucrat &executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw Form::GradeTooLowException();
}
