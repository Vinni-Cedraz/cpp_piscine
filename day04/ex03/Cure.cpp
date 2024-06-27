#include "Cure.hpp"
#include <iostream>

// Cannonical form:
Cure::Cure() : AMateria("cure") {}
Cure::Cure(const Cure &cure) : AMateria(cure) {}
Cure::~Cure() {}
Cure Cure::operator=(const Cure &cure) {
    type = cure.type;
    return *this;
}

// Other methods:
AMateria *Cure::clone() const { return new Cure(*this); }
void Cure::use(ICharacter &target) { std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; }
