#include "MateriaSource.hpp"
#include "color.hpp"
#include <iostream>

MateriaSource::MateriaSource() : IMateriaSource(), slot() {}

MateriaSource::MateriaSource(MateriaSource const &src) : IMateriaSource(), slot() {
    if (this != &src)
        *this = src;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src) {
    if (this != &src) {
        for (int i = 0; i < 4; i++) {
            delete slot[i];
            slot[i] = src.slot[i] ? src.slot[i]->clone() : 0;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
        delete slot[i];
}

void MateriaSource::learnMateria(AMateria *m) {
    for (int i = 0; i < 4; i++) {
        if (!slot[i]) {
            slot[i] = m;
            break;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
    for (int i = 0; i < 4; i++) {
        if (slot[i] && slot[i]->getType() == type) {
            return slot[i]->clone();
		}
    }
	std::cout << RED << "<MateriaSource> Materia " << GREEN << "'" << type << "' not found" << std::endl;
	return 0;
}
