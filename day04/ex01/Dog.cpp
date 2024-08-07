#include "Dog.hpp"
#include <iostream>
#include "color.hpp"

/* CONSTRUCTORS AND DESTRUCTOR */
Dog::Dog() : Animal() {
    std::cout << BLU "Dog Default Constructor Called" RESET << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog &obj) : Animal(obj), brain() {
    std::cout << BLU "Dog Copy Constructor Called" RESET << std::endl;
    this->brain = new Brain();
    *this = obj;
}

Dog::~Dog() {
    std::cout << RED "Dog Destructor Called" RESET << std::endl;
    delete this->brain;
}

/* OPERATORS OVERLOADING */
Dog &Dog::operator=(Dog const &other) {
    std::cout << CYN "Dog Copy Assignment Operator Called" RESET << std::endl;
    if (this != &other) {
        this->type = other.type;
        *(this->brain) = *(other.brain);
    }
    return (*this);
}

/* GETTERS AND SETTERS */
std::string Dog::getIdeaOfBrain(size_t index) const { return (this->brain->getIdea(index)); }

void Dog::setIdeaOfBrain(size_t index, std::string idea) { this->brain->setIdea(index, idea); }

/* MEMBER FUNCTIONS */
void Dog::makeSound(void) const { std::cout << GRN "The dog say: Auu!" RESET << std::endl; }
