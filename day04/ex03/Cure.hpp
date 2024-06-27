#pragma once

#include "AMateria.hpp"

#pragma once

class Cure : public AMateria {
  public:
    Cure();
    Cure(const Cure &ice);
    Cure operator=(const Cure &ice);
    virtual ~Cure();
    AMateria *clone() const;
	void use(ICharacter &target);
};
