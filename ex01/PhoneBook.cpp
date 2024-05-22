#include "PhoneBook.hpp"
#include <cstring>
#include <iostream>

PhoneBook::PhoneBook() { this->idx = 0; }

void PhoneBook::add_contact(const user_input_t &perfect_input) {
    contacts[idx].setUserInput(perfect_input);
    idx = (idx + 1) % 8; // reset idx to 0 if it reaches 8
}

void PhoneBook::display_contacts(void) {
    for (int i = 0; i < 8; i++) {
        const user_input_t input = contacts[i].getUserInput();
		if (input.first_name.empty())
			break ;
        std::cout << "First Name: " << input.first_name << std::endl;
        std::cout << "Last Name: " << input.last_name << std::endl;
        std::cout << "Nickname: " << input.nickname << std::endl;
        std::cout << "Phone Number: " << input.phone_number << std::endl;
        std::cout << "Darkest Secret: " << input.darkest_secret << std::endl;
    }
}

void PhoneBook::add_CMD() {
    user_input_t input;
    Parser parser;

    parser.parse_input(input);
    this->add_contact(input);
}
