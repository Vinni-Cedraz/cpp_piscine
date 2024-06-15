#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Anonymous ScavTrap") {};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap" << name << " is born!" << std::endl;
    setHit(100);
    setEnergy(50);
    setDamage(20);
};

void ScavTrap::setHit(int hit) { this->hit = hit; }
void ScavTrap::setEnergy(int energy) { this->energy = energy; }
void ScavTrap::setDamage(int damage) { this->damage = damage; }
void ScavTrap::setName(std::string name) { this->name = name; }

// destructor
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap" << name << " is destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
    OUT("ScavTrap ", name, " attacks ", target, ", causing ", damage, " points of damage!");
    RED("{ ", --energy, " points of energy left.}");
}

void ScavTrap::guardGate(void) { GREEN("ScavTrap ", name, " has entered in Gate keeper mode!"); }
