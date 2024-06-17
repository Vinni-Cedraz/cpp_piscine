#pragma once

#include "Animal.hpp"

class Dog : public Animal {
  public:
    Dog();
    Dog(const Dog &obj);
    ~Dog();
    Dog &operator=(Dog const &other);
    void makeSound(void) const;
};
