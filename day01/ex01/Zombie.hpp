#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
  private:
    std::string name;

  public:
	Zombie();
    *Zombie(std::string name);
    ~Zombie();
	void setName(std::string &name);
    void announce();
};

// it creates a zombie, name it, and return it so you can use it outside of the function scope
Zombie *newZombie(std::string name);
// it creates a zombie, name it, and the zombie anounces itself
void randomChump(std::string name);
// Allocates N zombie objects in a single allocation, then it initializes the zombies giving each of them the name
// passed as a parameter the function then returns a pointer to the first zombie
Zombie *zombieHorde(int N, std::string name);

#endif
