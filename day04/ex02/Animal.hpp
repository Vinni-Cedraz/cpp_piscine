#pragma once

#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

#include <string>

class Animal {
  protected:
    std::string type;

  public:
    Animal();
    Animal(const Animal &obj);
    Animal &operator=(Animal const &other);
    virtual ~Animal();
    std::string getType(void) const;
    void setType(std::string type);
    virtual void makeSound(void) const = 0;
};
