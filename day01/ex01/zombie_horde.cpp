#include "Zombie.hpp"
#include <iostream>

Zombie *zombieHorde(int N, std::string name) {
    Zombie *horde = new Zombie[N];
    for (int i = 0; i < N; i++) {
        std::cout << "#" << i + 1 << " says: ";
        horde[i].setName(name);
        horde[i].announce();
    }
    return horde;
}
