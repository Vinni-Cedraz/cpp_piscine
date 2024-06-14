#ifndef ClapTrap_HPP
#define ClapTrap_HPP

#include <iostream>
#include <string>
#define CYAN "\033[36m"
#define RESET "\033[0m"
#define RED(x, y, z) std::cout << "\033[31m" << x << y << z << "\033[0m" << std::endl
#define GREEN(x, y, z) std::cout << "\033[32m" << x << y << z << "\033[0m" << std::endl
#define OUT(a, b, c, d, e, f, g) std::cout << CYAN << a << b << c << d << e << f << g << RESET << std::endl

class ClapTrap {
  protected:
    std::string name;
    // hit represents the health
    int hit;
    // energy is expended to attack
    int energy;
    // damage is the amount of health to be taken from the target
    int damage;

  public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &other);
    ClapTrap operator=(const ClapTrap &other);
    ~ClapTrap();
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
