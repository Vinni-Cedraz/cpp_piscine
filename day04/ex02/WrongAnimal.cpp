#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() {
    std::cout << BLU "WrongAnimal: Default Constructor Called" RESET << std::endl;
    this->type = "";
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) {
    std::cout << BLU "WrongAnimal: Copy Constructor Called" RESET << std::endl;
    if (this != &obj)
        *this = obj;
}

WrongAnimal::~WrongAnimal() { std::cout << RED "WrongAnimal: Destructor Called" RESET << std::endl; }

/* OPERATORS OVERLOADING */
WrongAnimal &WrongAnimal::operator=(WrongAnimal const &other) {
    std::cout << CYN "WrongAnimal: Copy Assignment Operator Called" RESET << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

/* GETTERS AND SETTERS */
std::string WrongAnimal::getType(void) const { return (this->type); }

void WrongAnimal::setType(std::string type) { this->type = type; }

/* MEMBER FUNCTIONS */
void WrongAnimal::makeSound(void) const { std::cout << GRN "Default Wrong Animal Sound!" RESET << std::endl; }
