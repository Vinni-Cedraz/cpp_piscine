#pragma once
#include <string>

class Form;

class Intern {
  public:
    Intern();
    Intern(const Intern &copy);
    Intern &operator=(const Intern &assign);
    ~Intern();
    Form *makeForm(std::string formName, std::string target);
};

int index_of(const std::string &level);
void init_functions_table(void);
Form *shrubber(std::string target);
Form *robotomy(std::string target);
Form *presidential(std::string target);
Form *unexpected(std::string target);

#define TABLE_SIZE 20000
