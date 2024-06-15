#ifndef FragTrap_HPP
#define FragTrap_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
  public:
    FragTrap();
    ~FragTrap();
    FragTrap(std::string name);
    FragTrap(FragTrap const &src);
    FragTrap operator=(FragTrap const &src);
	void attack(std::string const &target);
    void highFivesGuys(void);
    void setHit(int hit);
    void setEnergy(int energy);
    void setDamage(int damage);
    void setName(std::string name);
};

#endif
