#include "Dog.hpp"
#include <iostream>

/* CONSTRUCTORS AND DESTRUCTOR */
Dog::Dog() : Animal() {
    std::cout << BLU "Dog Default Constructor Called" RESET << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &obj) : Animal(obj) {
    std::cout << BLU "Dog Copy Constructor Called" RESET << std::endl;
    if (this != &obj)
        *this = obj;
}

Dog::~Dog() { std::cout << RED "Dog Destructor Called" RESET << std::endl; }

/* OPERATORS OVERLOADING */
Dog &Dog::operator=(Dog const &other) {
    std::cout << CYN "Dog Copy Assignment Operator Called" RESET << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

/* MEMBER FUNCTIONS */
void Dog::makeSound(void) const { std::cout << GRN "The dog say: Auu!" RESET << std::endl; }
