#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void) {
    {
        std::cout << "TEST 1 (SUBJECT-TEST)" << std::endl;
        const Animal *meta = new Animal();
        const Animal *j = new Dog();
        const Animal *i = new Cat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        j->makeSound(); // will output the dog sound!
        i->makeSound(); // will output the cat sound!
        meta->makeSound();
        delete meta, delete j, delete i;
    }
    std::cout << std::endl;
    {
        std::cout << "TEST 2 (ANIMAL-AND-WRONG-ANIMAL-TEST)" << std::endl;
        std::cout << "-ANIMAL:" << std::endl;
        std::cout << "Constructors:" << std::endl;
        Animal *base;
        Cat derived1;
        Dog derived2;
        std::cout << std::endl;

        derived1.makeSound(); // cat sound obviously
        base = &derived1;
        base->makeSound(); // cat sound if implemented with virtual

        derived2.makeSound(); // dog sound obviously
        base = &derived2;
        base->makeSound(); // dog sound if implemented with virtual

        std::cout << std::endl;

        std::cout << "-WRONG ANIMAL:" << std::endl;
        std::cout << "Constructors:" << std::endl;
        WrongAnimal *Base;
        WrongCat Derived;
        std::cout << std::endl;

        Base = &Derived;
        Base->makeSound(); // will output the base generic sound instead of the wrong cat sound!! (no virtual)

        std::cout << std::endl;
        std::cout << "Destructors:" << std::endl;
    }
    return (0);
}
