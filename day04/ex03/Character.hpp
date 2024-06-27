#pragma once
#include "ICharacter.hpp"

class Character : public ICharacter {
  public:
    Character(std::string const &name);
    Character(Character const &src);
    Character &operator=(Character const &rhs);
    ~Character();

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);

  private:
    Character();
    std::string name;
    AMateria *slot[4];
};
