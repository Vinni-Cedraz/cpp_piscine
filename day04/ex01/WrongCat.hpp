#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
  public:
    WrongCat();
    WrongCat(const WrongCat &obj);
    ~WrongCat();
    WrongCat &operator=(WrongCat const &other);
    void makeSound(void) const;
};
