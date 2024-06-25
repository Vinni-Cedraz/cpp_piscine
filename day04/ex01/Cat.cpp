#include "Cat.hpp"
#include "color.hpp"
#include <iostream>

/* CONSTRUCTORS AND DESTRUCTOR */
Cat::Cat() : Animal() {
    std::cout << BLU "Cat Default Constructor Called" RESET << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat &obj) : Animal(obj) {
    std::cout << BLU "Cat Copy Constructor Called" RESET << std::endl;
    *this = obj;
}

Cat::~Cat() {
    std::cout << RED "Cat Destructor Called" RESET << std::endl;
    delete this->brain;
}

/* OPERATORS OVERLOADING */
Cat &Cat::operator=(Cat const &other) {
    std::cout << CYN "Cat Copy Assignment Operator Called" RESET << std::endl;
    if (this != &other) {
        this->type = other.type;
        this->brain = new Brain();
        *(this->brain) = *(other.brain);
    }
    return (*this);
}

/* GETTERS AND SETTERS */
std::string Cat::getIdeaOfBrain(size_t index) const { return (this->brain->getIdea(index)); }

void Cat::setIdeaOfBrain(size_t index, std::string idea) { this->brain->setIdea(index, idea); }

/* MEMBER FUNCTIONS */
void Cat::makeSound(void) const { std::cout << GRN "The cat say: Meow!" RESET << std::endl; }
