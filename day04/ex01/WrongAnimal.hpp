#pragma once

#include <string>

class WrongAnimal {
  protected:
    std::string type;

  public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &obj);
    ~WrongAnimal();
    WrongAnimal &operator=(WrongAnimal const &other);
    std::string getType(void) const;
    void setType(std::string type);
    void makeSound(void) const;
};
