#include "HumanA.hpp"
#include <ostream>
#include <iostream>
//Constructor:
HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {}

//Function to attack:
void HumanA::attack() const {
	std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}
