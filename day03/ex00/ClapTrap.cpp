#include "ClapTrap.hpp"

// default constructor
ClapTrap::ClapTrap() { std::cout << "Anonymous ClapTrap created" << std::endl; }
// name constructor
ClapTrap::ClapTrap(std::string name) : name(name), hit(10), energy(10), damage(0) {
    std::cout << "ClapTrap " << name << " is born!" << std::endl;
}
// copy constructor
ClapTrap::ClapTrap(const ClapTrap &other)
    : name(other.name), hit(other.hit), energy(other.energy), damage(other.damage) {
    std::cout << "ClapTrap " << name << " is born!" << std::endl;
}
// assignment operator
ClapTrap ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other) {
        name = other.name;
        hit = other.hit;
        energy = other.energy;
        damage = other.damage;
    }
    return *this;
}

// destructor
ClapTrap::~ClapTrap() { std::cout << "ClapTrap " << name << " is destroyed!" << std::endl; }

void ClapTrap::attack(const std::string &target) {
    OUT("ClapTrap ", name, " attacks ", target, " causing ", damage, " points of damage!");
	RED("{ ", --energy, " points of energy left.}");
}

void ClapTrap::takeDamage(unsigned int amount) {
    OUT("ClapTrap ", name, " takes ", amount, " points of damage!", "", "");
    hit = hit - amount;
	RED("{ Hit went down to ", hit, " }");
}

void ClapTrap::beRepaired(unsigned int amount) {
    OUT("ClapTrap ", name, " heals ", amount, " points of health!", "", "");
    hit = hit + amount;
	GREEN("{ Hit restored to ", hit, " }");
	RED("{ ", --energy, " points of energy left. }");
}
