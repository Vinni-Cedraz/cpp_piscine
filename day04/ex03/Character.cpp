#include "AMateria.hpp"
#include "Character.hpp"
#include "color.hpp"
#include <iostream>

// Cannonical:
Character::Character() : ICharacter(), slot() {}
Character::Character(std::string const &name) : ICharacter(), name(name), slot() {}

Character::Character(Character const &src) : ICharacter(), name(src.name), slot() {
    if (this != &src)
        *this = src;
}

Character &Character::operator=(const Character &src) {
    if (this != &src) {
        this->name = src.name;
        for (int i = 0; i < 4; i++) {
            delete slot[i];
            slot[i] = src.slot[i] ? src.slot[i]->clone() : 0;
        }
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++)
        delete slot[i];
}

// Other methods:
std::string const &Character::getName(void) const { return (this->name); }

void Character::equip(AMateria *m) {
    if (!m) {
        std::cout << RED << "<Character> Material not recognized" << RESET << std::endl;
        return delete m;
    }
    for (int i = 0; i < 4; i++) {
        if (slot[i] == NULL) {
            slot[i] = m->clone();
            return delete m;
        }
    }
    std::cout << RED << "<Character> slot is full" << RESET << std::endl;
    return delete m;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx > 4) {
        std::cout << RED << "Invalid idx. Please, try a valid index" << RESET << std::endl;
        return;
    } else if (this->slot[idx] == NULL) {
        std::cout << RED << "slot already empty" << RESET << std::endl;
        return;
    }
    std::cout << YELLOW << "Unequiping slot at idx '" << idx << "' | " << GREEN << this->slot[idx] << std::endl;
    slot[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
    if (idx < 0 || idx > 4) {
        std::cout << RED << "<Chracter> Invalid idx. Please, try a valid index" << RESET << std::endl;
        return;
    }
    if (slot[idx])
        slot[idx]->use(target);
    else
        std::cout << RED << "<Character> Empty index" << RESET << std::endl;
}
