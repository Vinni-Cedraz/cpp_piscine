#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
  private:
    std::string name;

  public:
    *Zombie(std::string name);
	~Zombie();
    void announce();
};

// it creates a zombie, name it, and return it so you can use it outside of the function scope
Zombie *newZombie(std::string name);
// it creates a zombie, name it, and the zombie anounces itself
void randomChump(std::string name);

#endif
