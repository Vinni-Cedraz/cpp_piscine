#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Anonymous ClapTrap") {}

FragTrap::~FragTrap() { std::cout << "FragTrap " << name << " is dead!" << std::endl; }

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap " << name << " is born!" << std::endl;
    setHit(100);
    setEnergy(100);
    setDamage(30);
}

FragTrap::FragTrap(const FragTrap &src) {
    if (this != &src)
        *this = src;
}

FragTrap FragTrap::operator=(FragTrap const &src) {
    if (this != &src) {
        setName(src.name);
        setHit(src.hit);
        setEnergy(src.energy);
        setDamage(src.damage);
    }
    return *this;
}


void FragTrap::attack(std::string const &target) {
    OUT("ClapTrap ", name, " attacks ", target, " causing ", damage, " points of damage!");
    RED("{ ", --energy, " points of energy left.}");
}

void FragTrap::highFivesGuys(void) { std::cout << "High five guys!" << std::endl; }

// setters:
void FragTrap::setHit(int hit) { this->hit = hit; }
void FragTrap::setEnergy(int energy) { this->energy = energy; }
void FragTrap::setDamage(int damage) { this->damage = damage; }
void FragTrap::setName(std::string name) { this->name = name; }
