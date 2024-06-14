#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap padrao") {};

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ClapTrap " << name << " is born!" << std::endl;
	setHit(100);
	setEnergy(50);
	setDamage(20);
};


void ScavTrap::setHit(int hit) {
	this->hit = hit;
}
void ScavTrap::setEnergy(int energy) {
	this->energy = energy;
}
void ScavTrap::setDamage(int damage) {
	this->damage = damage;
}
void ScavTrap::setName(std::string name) {
	this->name = name;
}

// destructor
ClapTrap::~ClapTrap() { std::cout << "ClapTrap " << name << " is destroyed!" << std::endl; }

void ScavTrap::attack(const std::string &target) {
	ClapTrap donald;
	donald.beRepaired(12);
	std::cout << "I am ScavTrap " << "I attack " << target << std::endl;
}
