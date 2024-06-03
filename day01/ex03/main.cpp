#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
	{
		Weapon club = Weapon("crude spiked club");
		HumanB Jim("Jim");
		Jim.setWeapon(club);
        club.setType("crude spiked club");
        Jim.attack();
        club.setType("some other type of club");
        Jim.attack();
	}
}
