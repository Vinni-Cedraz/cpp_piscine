#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
  public:
    Dog();
    Dog(const Dog &obj);
    ~Dog();
    Dog &operator=(Dog const &other);
    std::string getIdeaOfBrain(size_t index) const;
    void setIdeaOfBrain(size_t index, std::string idea);
    void makeSound(void) const;

  private:
    Brain *_brain;
};
