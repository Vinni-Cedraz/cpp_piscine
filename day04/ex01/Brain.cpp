#include "Brain.hpp"
#include <iostream>

/* CONSTRUCTORS AND DESTRUCTOR */
Brain::Brain() {
    std::cout << BLU "Brain Default Constructor Called" RESET << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "No idea";
}

Brain::Brain(const Brain &obj) {
    std::cout << BLU "Brain Copy Constructor Called" RESET << std::endl;
    if (this != &obj)
        *this = obj;
}

Brain::~Brain() { std::cout << RED "Brain Destructor Called" RESET << std::endl; }

/* OPERATORS OVERLOADING */
Brain &Brain::operator=(const Brain &other) {
    std::cout << CYN "Brain Copy Assignment Operator Called" RESET << std::endl;
    std::copy(other.ideas, &other.ideas[99], this->ideas);
    return (*this);
}

/* GETTERS AND SETTERS */
std::string Brain::getIdea(size_t index) const {
    if (index >= 100) {
        std::cout << "index out of range!" << std::endl;
        return ("");
    }
    return (this->ideas[index]);
}

void Brain::setIdea(size_t index, std::string idea) {
    if (index >= 100) {
        std::cout << "index out of range!" << std::endl;
        return;
    }
    this->ideas[index] = idea;
}
