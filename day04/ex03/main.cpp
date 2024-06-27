#include "Character.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "color.hpp"
#include <iostream>

int main(void) {
    std::cout << WHT << "********** SUBJECT TEST **********\n" << RESET;
    {
        IMateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice()); // add types allowed of materials
        src->learnMateria(new Cure());

        ICharacter *me = new Character("me"); // creating the character to use this materials

        std::cout << MAG << "\n----------> Verify material <----------\n" << RESET << std::endl;
        AMateria *tmp;
        tmp = src->createMateria("batata"); // invalid material, doesn't have to add
        me->equip(tmp);                     // invalid
        tmp = src->createMateria("cure");   // ok
        me->equip(tmp);                     // ok
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        tmp = src->createMateria("ice");
        me->equip(tmp);

        std::cout << MAG << "\n----------> Character + use <----------\n" << RESET << std::endl;
        ICharacter *bob = new Character("Bob"); // target
        me->use(0, *bob);
        me->use(1, *bob);

        delete bob;
        delete me;
        delete src;
    }

    std::cout << "\n";
    {
        std::cout << WHT << "********** DEEP COPY TEST **********\n" << RESET << std::endl;
        IMateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice());

        Character *original = new Character("Original");

        AMateria *tmp;
        tmp = src->createMateria("ice");
        original->equip(tmp);

        std::cout << MAG << "\n----------> Original vs Copy <----------\n" << RESET << std::endl;
        Character *copy = new Character(*original);
        std::cout << YELLOW << "Original name: " << GREEN << original->getName() << std::endl;
        std::cout << YELLOW << "Copy name: " << GREEN << copy->getName() << std::endl;
        Character target("target");

        std::cout << MAG << "\n----------> Equal prints <----------\n" << RESET << std::endl;
        original->use(0, target);
        copy->use(0, target);

        std::cout << MAG << "\n----------> Different prints <----------\n" << RESET << std::endl;
        src->learnMateria(new Cure());
        tmp = src->createMateria("cure");
        original->equip(tmp);
        original->use(1, target);
        copy->use(1, target);

        delete copy;
        delete original;
        delete src;
    }
}
