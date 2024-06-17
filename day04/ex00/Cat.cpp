#include "Cat.hpp"
#include <iostream>

/* CONSTRUCTORS AND DESTRUCTOR */
Cat::Cat() : Animal() {
    std::cout << BLU "Cat Default Constructor Called" RESET << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &obj) : Animal(obj) {
    std::cout << BLU "Cat Copy Constructor Called" RESET << std::endl;
    if (this != &obj)
        *this = obj;
}

Cat::~Cat() { std::cout << RED "Cat Destructor Called" RESET << std::endl; }

/* OPERATORS OVERLOADING */
Cat &Cat::operator=(Cat const &other) {
    std::cout << CYN "Cat Copy Assignment Operator Called" RESET << std::endl;
    if (this != &other)
        this->type = type;
    return (*this);
}

/* MEMBER FUNCTIONS */
void Cat::makeSound(void) const { std::cout << GRN "The cat say: Meow!" RESET << std::endl; }
