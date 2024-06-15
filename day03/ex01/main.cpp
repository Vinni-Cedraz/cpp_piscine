#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ScavTrap scav("James");
	ClapTrap clap("outro");
    scav.attack("Kim Jong Un");
	clap.attack("aline");
    scav.takeDamage(5);
    scav.beRepaired(5);
    scav.takeDamage(5);
    scav.takeDamage(5);
	scav.guardGate();
}
