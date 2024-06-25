#pragma once

#include <string>

class Animal {
  protected:
    std::string type;

  public:
    Animal();
    Animal(const Animal &obj);
   virtual ~Animal();
    Animal &operator=(Animal const &other);
    std::string getType(void) const;
    void setType(std::string type);
    virtual void makeSound(void) const;
};
