#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : Form("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : Form(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
    if (this == &other)
        return *this;
    Form::operator=(other);
    target = other.target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	checkGrade(executor);
    std::ofstream file((target + "_shrubbery").c_str());
    if (file.fail()) {
        std::cerr << "Error opening file\n";
        return;
    }
    file << "     ^\n"
            "    ^^^\n"
            "   ^^^^^\n"
            "  ^^^^^^^\n"
            " ^^^^^^^^^\n"
            "^^^^^^^^^^^\n"
            "     ||\n"
            "     ||\n";
    file.close();
}
