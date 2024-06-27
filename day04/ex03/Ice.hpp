#include "AMateria.hpp"

#pragma once

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice &ice);
		Ice operator=(const Ice &ice);
		virtual ~Ice();
		AMateria *clone() const;
		void use(ICharacter &target);
};
