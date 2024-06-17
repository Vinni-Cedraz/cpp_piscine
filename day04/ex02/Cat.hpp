#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
  public:
    Cat();
    Cat(const Cat &obj);
    ~Cat();
    Cat &operator=(Cat const &other);
    std::string getIdeaOfBrain(size_t index) const;
    void setIdeaOfBrain(size_t index, std::string idea);
    void makeSound(void) const;

  private:
    Brain *_brain;
};
