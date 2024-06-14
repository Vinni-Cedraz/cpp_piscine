#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
  public:
    ScavTrap();
    ScavTrap(const std::string name);
    ScavTrap(const ClapTrap &other);
    ScavTrap operator=(const ClapTrap &other);
    void attack(const std::string &target);
    void guardGate();
    void setHit(int hit);
    void setEnergy(int energy);
    void setDamage(int damage);
    void setName(std::string name);
};
