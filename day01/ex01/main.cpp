#include "Zombie.hpp"
#include <iostream>

#define CYAN "\033[36m"
#define RESET "\033[0m"

#define scenario1 \
"\n\
When Zombie z = zombieHorde(3, \"Zombie\")\n\
Then it should print:\n\
	#1 says: Zombie: BraiiiiiiinnnzzzZ...\n\
	#2 says: Zombie: BraiiiiiiinnnzzzZ...\n\
	#3 says: Zombie: BraiiiiiiinnnzzzZ...\n\
	Zombie is dead\n\
	Zombie is dead\n\
	Zombie is dead\n"

#define scenario2                                                                                                      \
    "\n\
When Zombie z = zombieHorde(10, \"Zombie\")\n\
Then it should print:\n\
	#1 says: Zombie: BraiiiiiiinnnzzzZ...\n\
	#2 says: Zombie: BraiiiiiiinnnzzzZ...\n\
	#3 says: Zombie: BraiiiiiiinnnzzzZ...\n\
	#4 says: Zombie: BraiiiiiiinnnzzzZ...\n\
	#5 says: Zombie: BraiiiiiiinnnzzzZ...\n\
	#6 says: Zombie: BraiiiiiiinnnzzzZ...\n\
	#7 says: Zombie: BraiiiiiiinnnzzzZ...\n\
	#8 says: Zombie: BraiiiiiiinnnzzzZ...\n\
	#9 says: Zombie: BraiiiiiiinnnzzzZ...\n\
	#10 says: Zombie: BraiiiiiiinnnzzzZ...\n\
	Zombie is dead\n\
	Zombie is dead\n\
	Zombie is dead\n\
	Zombie is dead\n\
	Zombie is dead\n\
	Zombie is dead\n\
	Zombie is dead\n\
	Zombie is dead\n\
	Zombie is dead\n\
	Zombie is dead\n"

int main() {
    std::cout << CYAN scenario1 RESET << std::endl;
    {
        Zombie *z = zombieHorde(3, "Zombie");
        delete[] z;
    }
    std::cout << CYAN scenario2 RESET << std::endl;
    {
        Zombie *z = zombieHorde(10, "Zombie");
        delete[] z;
    }
}
