#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdlib>
#include <iostream>

#define ANIMALS 6
namespace tests {
void correct_default_constructors() {
    std::cout << YEL << "TEST 1 - Correct default constructors" << RESET << std::endl;
    Animal *i = new Dog();
    Animal *j = new Cat();
    std::cout << std::endl;

    i->makeSound();
    j->makeSound();

    delete i, delete j;
    std::cout << std::endl;
}

void correct_copy_constructors() {
    std::cout << YEL << "TEST 2 - Correct COPY Constructors" << RESET << std::endl;

    Dog a;
    a.setIdeaOfBrain(99, "Misto Quente");
    Dog b(a);
    std::cout << "Dog b -> Brain last idea (must be \"misto quente\"):" << std::endl;
    std::cout << b.getIdeaOfBrain(99) << std::endl;
    std::cout << YEL << "TEST 3 - Correct COPY Constructor with assignment overload" << RESET << std::endl;
    Dog c = a;
    std::cout << "Dog c -> Brain last idea (must be \"misto quente\"):" << std::endl;
    std::cout << c.getIdeaOfBrain(99) << std::endl;
}

void wrong_constructors() {
    std::cout << YEL << "TEST 4 - WRONG Constructors" << RESET << std::endl;
    WrongAnimal *i = new WrongCat();
    i->makeSound(); // will print "default wrong animal sound"
    delete i;
}

void copy_assignment_operator() {
    std::cout << YEL << "TEST 5 (COPY ASSIGNMENT OPERATOR)" << RESET << std::endl;

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
    std::cout << "Now we copy the dog1 to dog2 (dog2 = dog1): " << std::endl;
    dog2 = dog1;
    std::cout << "Dog 2 -> Brain ideas:" << std::endl;
    for (int i = 0; i < 10; i++)
        std::cout << dog2.getIdeaOfBrain(i) << std::endl;
    std::cout << std::endl;
}

void virtual_makesound() {
    std::cout << "TEST 6 (ARRAY OF ANIMALS)" << std::endl;

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

void scope_deep_copy() {
    std::cout << YEL << "TEST 7 (SCOPE DEEP COPY)" << RESET << std::endl;
    Dog a;
    { Dog tmp = a; }
    std::cout << BLD << "\n\nGiven Dog tmp = a; AND tmp leaves scope." << std::endl;
    std::cout << "THEN Dog a still exists!\n" RESET << std::endl;
    std::cout << "Dog a sound:" << std::endl;
    a.makeSound(); // must return "The dog say: Auu!"
}
} // namespace tests

int main(void) {
    tests::correct_default_constructors();
    tests::correct_copy_constructors();
    tests::wrong_constructors();
    tests::copy_assignment_operator();
    tests::virtual_makesound();
    tests::scope_deep_copy();
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
}
