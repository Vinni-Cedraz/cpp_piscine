#include "AMateria.hpp"
AMateria::AMateria() : type("") {}

AMateria::AMateria(std::string const &type) : type(type) {};

AMateria::AMateria(const AMateria &obj) { (void)obj; }

AMateria &AMateria::operator=(const AMateria &other) {
    if (this != &other) {
        // Do not copy the type
    }
    return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const { return type; }

void AMateria::use(ICharacter &target) { (void)target; }
