#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ScavTrap scav("James");
    scav.attack("Kim Jong Un");
    scav.takeDamage(5);
    scav.beRepaired(5);
    scav.takeDamage(5);
    scav.takeDamage(5);
	scav.guardGate();
}
