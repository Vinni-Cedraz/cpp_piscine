#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// This is the table of form-creating functions:
Form *(*lookup_table[TABLE_SIZE])(std::string target);

// Orthodox cannonical form
Intern::Intern() { init_functions_table(); }
Intern::Intern(const Intern &copy) { *this = copy; }
Intern::~Intern() {}
Intern &Intern::operator=(const Intern &assign) {
    (void)assign;
    return *this;
}

// Intern's method:
Form *Intern::makeForm(std::string formName, std::string target) {
    Form *new_form = (lookup_table[index_of(formName)])(target);
    return new_form;
}

// Form-creating functions:
Form *shrubber(std::string target) { return new ShrubberyCreationForm(target); }
Form *robotomy(std::string target) { return new RobotomyRequestForm(target); }
Form *presidential(std::string target) { return new PresidentialPardonForm(target); }
Form *unexpected(std::string target) {
	std::cerr << RED "Intern: Form not found" RESET << std::endl;
	(void)target;
	return NULL;
}

// Lookup table implementation:
void init_functions_table(void) {
    for (int i = 0; i < TABLE_SIZE; i++)
        lookup_table[i] = &unexpected;
    lookup_table[index_of("robotomy request")] = &robotomy;
    lookup_table[index_of("shrubbery creation request")] = &shrubber;
    lookup_table[index_of("presidential pardon request")] = &presidential;
}

int index_of(const std::string &level) {
    int hash = 5381;
    for (int i = 0; i < (int)level.length(); ++i)
        hash = ((hash << 5) + hash) + level[i];
    return (hash & 0b11111111111 % TABLE_SIZE);
}
