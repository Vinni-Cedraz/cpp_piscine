#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdlib>
#include <iostream>

#define ANIMALS 6

namespace tests {
void correct_constructors() {
    std::cout << "TEST 1" << std::endl;

    std::cout << "Correct constructors:" << std::endl;
    Animal *i = new Dog();
    Animal *j = new Cat();
    std::cout << std::endl;

    i->makeSound();
    j->makeSound();

    delete i, delete j;
    std::cout << std::endl;
}

void wrong_constructors() {
    std::cout << "TEST 1 - WRONG Constructors" << std::endl;
    WrongAnimal *i = new WrongCat();
    i->makeSound(); // will print "Wrong meow"
    delete i;
}

void copy_assingment_operator() {
    std::cout << "TEST 2 (COPY ASSIGNMENT OPERATOR)" << std::endl;

    std::cout << "Constructors:" << std::endl;
    Dog dog1;
    Dog dog2;

    for (int i = 0; i < 10; i += 2) {
        dog1.setIdeaOfBrain(i, "Misto Quente");
        dog1.setIdeaOfBrain(i + 1, "Feijoada");
    }
    std::cout << "Dog 1 -> Brain ideas:" << std::endl;
    for (int i = 0; i < 10; i++)
        std::cout << dog1.getIdeaOfBrain(i) << std::endl;
    std::cout << "Dog 2 -> Brain ideas:" << std::endl;
    for (int i = 0; i < 10; i++)
        std::cout << dog2.getIdeaOfBrain(i) << std::endl;
    std::cout << "Now we copy the dog1 to dog2: " << std::endl;
    dog2 = dog1;
    std::cout << "Dog 2 -> Brain ideas:" << std::endl;
    for (int i = 0; i < 10; i++)
        std::cout << dog2.getIdeaOfBrain(i) << std::endl;
    std::cout << std::endl;
}

void virtual_makesound() {
    std::cout << "TEST 3 (ARRAY OF ANIMALS)" << std::endl;

    // return error and exit if ANIMALS is an odd number
    if (ANIMALS % 2) {
        std::cerr << "ANIMALS must be an even number" << std::endl;
        exit(1);
    }
    Animal *animals[ANIMALS];
    for (int i = 0; i < ANIMALS / 2; i++)
        animals[i] = new Dog();
    for (int i = ANIMALS / 2; i < ANIMALS; i++)
        animals[i] = new Cat();

    std::cout << std::endl;
    for (int i = 0; i < ANIMALS; i++) {
        animals[i]->makeSound();
    }
    for (int i = 0; i < ANIMALS; i++) {
        delete animals[i];
    }
    std::cout << std::endl;
}
} // namespace tests

int main(void) {
    tests::correct_constructors();
    tests::wrong_constructors();
    tests::copy_assingment_operator();
    tests::virtual_makesound();
    std::cout << std::endl;
    {
        std::cout << "FINAL VIRTUAL METHOD TEST" << std::endl;
        std::cout << "Constructors:" << std::endl;
        Dog dog;
        Cat cat;
        // Animal	instance;
        Animal *a = &dog;
        Animal *b = &cat;
        std::cout << std::endl;

        a->makeSound();
        b->makeSound();

        std::cout << std::endl;
        std::cout << "Destructors" << std::endl;
    }
    return (0);
}
