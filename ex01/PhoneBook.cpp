#include "PhoneBook.hpp"
#include <cstring>
#include <iostream>
#include <string>

PhoneBook::PhoneBook() { this->idx = 0; }

void PhoneBook::add_contact(std::string name, std::string number) {
    contacts[idx].setNameNumber(name, number);
    idx = (idx + 1) % 8; // reset idx to 0 if it reaches 8
}

void PhoneBook::display_contacts(void) {
    for (int i = 0; i < 8; i++) {
        if (contacts[i].getName().empty())
            return;
        const std::string name = contacts[i].getName();
        const std::string number = contacts[i].getNumber();
        std::cout << "Name: " << name << ", Number: " << number << std::endl;
    }
}
