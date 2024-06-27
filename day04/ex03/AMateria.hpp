#pragma once

#include "ICharacter.hpp"
#include <string>

class AMateria {
  protected:
    std::string type;

  public:
    AMateria();
    AMateria(std::string const &type);
    AMateria(const AMateria &obj);
    AMateria &operator=(const AMateria &other);
    virtual ~AMateria();

    std::string const &getType() const;
    virtual void use(ICharacter &target);
    virtual AMateria *clone() const = 0;
	static AMateria *createMateria(std::string const &type);
};
