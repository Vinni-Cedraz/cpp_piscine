#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap clap("James");
    clap.attack("Kim Jong Un");
    clap.takeDamage(5);
    clap.beRepaired(5);
    clap.takeDamage(5);
    clap.takeDamage(5);
	ScavTrap kevin;
	kevin.attack("Andrey");
}
