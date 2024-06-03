#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(){} * Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie() { std::cout << name << " is dead" << std::endl; }

void Zombie::announce() { std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl; }

Zombie *newZombie(std::string name) { return new Zombie(name); }

void randomChump(std::string name) {
    Zombie z(name);
    z.announce();
}

void Zombie::setName(std::string &name) { this->name = name; }
