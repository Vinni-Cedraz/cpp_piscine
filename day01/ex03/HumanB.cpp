#include "HumanB.hpp"
#include <ostream>
#include <iostream>
//Constructor:
HumanB::HumanB(std::string name) : name(name), weapon(){}

//Function to attack:
void HumanB::attack() const {
	std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}
