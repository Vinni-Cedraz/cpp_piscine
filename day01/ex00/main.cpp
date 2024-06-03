#include "Zombie.hpp"

int main() {
    Zombie *zombie = newZombie("Heap Zombie");
    zombie->announce();
    randomChump("Stack Zombie");
	delete zombie;
}
